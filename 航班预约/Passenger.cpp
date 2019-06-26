#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Flight.cpp"

using namespace std;

class Passenger
{
private:
	string name;
	string num;
	string nationality;
	string tel;
public:
	vector<string> flight;
	Passenger(string na, string nu, string nati, string t)
	{
		name = na;
		nationality = nati;
		num = nu;
		tel = t;
	}

	string getName()
	{
		return name;
	}

	string getNum()
	{
		return num;
	}

	string getNationality()
	{
		return nationality;
	}

	string getTel()
	{
		return tel;
	}

	int addFlight(string fl)
	{
		for(vector<string>::iterator it = flight.begin(); it != flight.end(); it++)
		{
			if((*it).compare(fl) == 0)
			{
				cout << "已经预约过!不可重复预约!本次支付失败!" << endl;
				return -1;
			}
		}

		flight.push_back(fl);
		return 1;
	}

	int removeFlight(string fl)
	{
		for(vector<string>::iterator it = flight.begin(); it != flight.end(); it++)
		{
			if((*it).compare(fl) == 0)
			{
				flight.erase(it);
				return 1;
			}
		}
		return -1;
	}

	void showFlight(string fl, vector<Flight*> fli)
	{
		for(vector<Flight*>::iterator it = fli.begin(); it != fli.end(); it++)
		{
			if((*it)->getFlight().compare(fl) == 0)
			{
				(*it)->showInfo();
				cout << endl;
				break;
			}
		}
	}
	void setName(string na)
	{
		name = na;
	}

	void setNum(string nu)
	{
		num = nu;
	}

	void setNationality(string nati)
	{
		nationality = nati;
	}

	void setTel(string t)
	{
		tel = t;
	} 

	void showInfo()
	{
		cout << "name:" << name << endl << "passport:" << num << endl << "nationality:" << nationality << endl << "tel:" << tel << endl;
	}
};

/*
int main()
{
	vector<Passenger*> P;
	vector<Passenger*>::iterator it;
	
	P.push_back(new Passenger("1","1","1","1"));
	P.push_back(new Passenger("2","2","2","2"));
	P.push_back(new Passenger("3","3","3","3"));

	for(it = P.begin(); it != P.end(); it++)
	{
		if((*it)->getName().compare("2") == 0)
			it=P.erase(it);
		(*it)->showInfo();
	}
	return 0;
}
*/