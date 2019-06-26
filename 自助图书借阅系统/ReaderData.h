class ReaderData : public Object  
{
protected:
	long PIN;
	char name[20];
	long BookList[LIMIT];
	Date BorrowDate[LIMIT];
	int num;

public:
	ReaderData()
	{
		PIN=0;
		num=0;
		for(int i=0; i<LIMIT ;++i)
			BookList[i]=0;
	}

	ReaderData(int PIN,char *name)
	{
		SetID(PIN);
		SetName(name);
		num=0;
		for(int i=0;i<LIMIT;++i)
			BookList[i]=0;
	}

	void SetID(long PIN){this->PIN = PIN;}
	void SetName(const char * i_name){strcpy(name , i_name);}
	long GetID(){return PIN;}
	const char * GetName(){return name;}
	int GetNum(){return num;}
	long BorrowBook(long);
	void ShowData();
	long ReturnBook(long);
};

long ReaderData::ReturnBook(long BookID)
{
	for(int i=0;i<LIMIT;++i)
		if(BookList[i]==BookID)
		{
			BookList[i]=0;
			num--;
			return BookID;
		}
	return 0;
}

void ReaderData::ShowData()
{
	cout<<PIN<<'\t'<<name<<endl;
	for(int i=0;i<LIMIT;i++)
	{
		if(BookList[i])
		{
			cout<<i+1<<":"<<BookList[i]<<'\t';
			BorrowDate[i].display();
		}
	}
}

long ReaderData::BorrowBook(long BookID)
{
	for(int i=0;i<LIMIT;++i)
		if(BookList[i]==0)
		{
			BookList[i]=BookID;
			BorrowDate[i]=Date();
			num++;
			return BookID;
		}
	cout<<"Book reach the limit£¡"<<endl;
	return 0;
}