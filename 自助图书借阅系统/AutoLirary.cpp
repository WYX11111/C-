#pragma warning (disable:4786)
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<map>
#include "global.h"
#include "date.h"
#include "BookData.h"
#include "ReaderData.h"
#include "database.h"
#include "librarian.h"
#include "reader.h"

using namespace std;

int main()
{
	Database<BookData>BookBase("books.dat");
	Database<ReaderData>ReaderBase("readers.dat");

	char choice = 'X';
	while (!(choice == 'E'||choice == 'e'))
	{
		cout << "(L)ibrarian entry, (R)eader entry, Re(t)urn book, (E)xit:";
		cin >> choice;
		Librarian * mgr = NULL;
		Reader * rdr = NULL;

		switch (choice)
		{
		case 'L': case 'l':
			mgr = new Librarian(101, "yjc");
			choice = mgr->login(); 
			while (!(choice == 'E'||choice == 'e'))
			{
				cout << "(A)dd reader, Add (B)ook, (Q)uery Reader, (P)ut book to shelf, (E)xit:";
				cin >> choice;

				switch (choice)
				{
					long ID;
					char name[40];
				case 'A': case 'a':
					cout << "Give a reader PIN and input a name:";
					cin >> ID;
					cin.ignore();
					cin.get(name, 20, '\n');
					ReaderBase.Insert(ReaderData(ID, name));
					break;

				case 'B': case 'b':
					cout << "Input a book ID and name:";
					cin >> ID;
					cin.ignore();
					cin.get(name, 40, '\n');
					BookBase.Insert(BookData(ID, name));
					break;

				case 'Q': case 'q':
					cout << "Input a reader's PIN:";
					cin >> ID;
					if (ReaderBase.Query(ID) == NULL)
					{
						cout << "No such a reader! " << endl;
					} else
					{
						ReaderBase.Query(ID)->ShowData();
					}
					break;

				case 'P': case 'p':
					cout << "Input a book ID:";
					cin >> ID;
					if (BookBase.Query(ID) == NULL)
					{
						cout << "No such a book!" << endl;
					} else
					{
						BookBase.Query(ID)->SetState(SHELF);
					}
					break;

				case 'S': case 's':
					ReaderBase.ShowAllData();
					BookBase.ShowAllData();
					break;

				case 'E': case 'e':
					break;
					
				default:
					cout << "Unavailable Function!" << endl;
				}
			}

		    delete mgr;
		    choice = 'X';
		    break;

		case 'R': case 'r':
			long PIN, BookID;
			int i, t1, t2;
			char name[40];

			for (i = 0; i < 3; i ++)
			{
				cout << "Input PIN:";
				cin >> PIN;
				if (ReaderBase.Query(PIN) != NULL)
				{
					rdr = new Reader(PIN);
					break;
				}
			}

			if (i == 3)
			{
				cout << "Check In Failed!" << endl;
				choice = 'E';
			}

			while (!(choice == 'E'||choice == 'e'))
			{
				cout << "(A)dd book to Cart, Check (O)out, (Q)uery Book By Name, (L)ist My Books, (E)xit:";
				cin >> choice;
				switch (choice)
				{
				case 'A': case 'a':
					cout << "Input a Book ID:";
					cin >> BookID;
					if ((BookBase.Query(BookID) != NULL && BookBase.Query(BookID)->GetState() == SHELF))
					{
						if (rdr->AddBook(BookID))
							BookBase.Query(BookID)->SetState(LIB);
					}
					break;

				case 'O': case 'o':
					t1 = rdr->GetNum();
					t2 = ReaderBase.Query(PIN)->GetNum();

					if (t1 > 0 && t2 < LIMIT)
					{
						cout << PIN << " " << ReaderBase.Query(PIN)->GetName() << " Book List" << endl;
						for (i = 0; i < t1 && i < (LIMIT - t2); i ++)
						{
							BookID = ReaderBase.Query(PIN)->BorrowBook(rdr->CheckOut());
							BookBase.Query(BookID)->SetState(READER);
							BookBase.Query(BookID)->SetPIN(PIN);
							cout << i + 1 << '\t' << BookBase.Query(BookID)->GetName() << endl;
						}
						Date().display();
					}
    				break;

				case 'Q': case 'q':
					cout << "Input a book name (part):";
					cin.ignore();
					cin.get(name, 40, '\n');
					if (BookBase.QueryName(name) != NULL)
					{
						BookBase.QueryName(name)->ShowData();
					}
					break;

				case 'L': case 'l':
					ReaderBase.Query(PIN)->ShowData();
					break;
						
				case 'C': case 'c':
					rdr->ShowCart();
					break;

				case 'E': case 'e':
					break;

				default:
					cout << "Unavailable Function!" << endl;
				}
			}

			delete mgr;
			choice = 'X';
			break;

		case 'T': case 't':
			cout << "Input a book ID:";
			cin >> BookID;

			if (BookBase.Query(BookID) != NULL)
			{
				BookBase.Query(BookID)->SetState(LIB);
				if ((PIN = BookBase.Query(BookID)->GetPIN()) > 0)
				{
					ReaderBase.Query(PIN)->ReturnBook(BookID);
				}
			}

			break;

		case 'E': case 'e':
			break;

		default:
			cout << "Unavailable Function!" << endl;
		}
	}
	return 0;
}