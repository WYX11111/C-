#include <string>
#include <iostream>
#include <vector>
#include "Flight.cpp"

using namespace std;

class Passenger
{
private:
	string name;         //姓名
	string num;          //护照号
	string nationality;  //国籍
	string tel;          //联系电话
public:
	vector<string> flight;   //用一个vector记录下该乘客的航班号
	Passenger(string na, string nu, string nati, string t) //构造函数
	{
		name = na;
		nationality = nati;
		num = nu;
		tel = t;
	}

	//set get函数
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

	//增加航班，向记录航班号的vector中增加航班号，用于预约航班
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

	//删除航班，向记录航班号的vector中删除航班号，用于取消航班预约
	int removeFlight(string fl)
	{
		for(vector<string>::iterator it = flight.begin(); it != flight.end(); it++)
		{
			if((*it).compare(fl) == 0)   //先在vector中找打要删除的航班号
			{
				flight.erase(it);
				return 1;
			}
		}
		return -1;
	}

	//显示该乘客航班的具体信息
	void showFlight(string fl, vector<Flight*> fli)
	{
		for(vector<Flight*>::iterator it = fli.begin(); it != fli.end(); it++) //遍历储存的航班信息的vector
		{
			if((*it)->getFlight().compare(fl) == 0) //找到该乘客航班号
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

	//显示乘客信息及乘客已经预约的航班号
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