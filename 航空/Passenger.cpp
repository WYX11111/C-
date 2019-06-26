#include <string>
#include <iostream>
#include <vector>
#include "Flight.cpp"

using namespace std;

class Passenger
{
private:
	string name;         //����
	string num;          //���պ�
	string nationality;  //����
	string tel;          //��ϵ�绰
public:
	vector<string> flight;   //��һ��vector��¼�¸ó˿͵ĺ����
	Passenger(string na, string nu, string nati, string t) //���캯��
	{
		name = na;
		nationality = nati;
		num = nu;
		tel = t;
	}

	//set get����
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

	//���Ӻ��࣬���¼����ŵ�vector�����Ӻ���ţ�����ԤԼ����
	int addFlight(string fl)
	{
		for(vector<string>::iterator it = flight.begin(); it != flight.end(); it++)
		{
			if((*it).compare(fl) == 0)
			{
				cout << "�Ѿ�ԤԼ��!�����ظ�ԤԼ!����֧��ʧ��!" << endl;
				return -1;
			}
		}

		flight.push_back(fl);
		return 1;
	}

	//ɾ�����࣬���¼����ŵ�vector��ɾ������ţ�����ȡ������ԤԼ
	int removeFlight(string fl)
	{
		for(vector<string>::iterator it = flight.begin(); it != flight.end(); it++)
		{
			if((*it).compare(fl) == 0)   //����vector���Ҵ�Ҫɾ���ĺ����
			{
				flight.erase(it);
				return 1;
			}
		}
		return -1;
	}

	//��ʾ�ó˿ͺ���ľ�����Ϣ
	void showFlight(string fl, vector<Flight*> fli)
	{
		for(vector<Flight*>::iterator it = fli.begin(); it != fli.end(); it++) //��������ĺ�����Ϣ��vector
		{
			if((*it)->getFlight().compare(fl) == 0) //�ҵ��ó˿ͺ����
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

	//��ʾ�˿���Ϣ���˿��Ѿ�ԤԼ�ĺ����
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