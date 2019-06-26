#include <string>
#include <iostream>
using namespace std;

class Flight
{
private:
	string flg;
	string b_place;
	string e_place;
	int b_month;
	int e_month;
	int b_data;
	int e_data;
	int b_hour;
	int e_hour;
	int b_min;
	int e_min;
	int price;
	string type;
	int sum;
	int n;

public:
	Flight(string flg, string b_place, string e_place, int b_month, int b_data, int b_hour, int b_min, int e_month, int e_data, int e_hour, int e_min, int price, string type, int sum, int n)
	{
		this->flg = flg;
		this->b_place = b_place;
		this->e_place = e_place;
		this->b_month = b_month;
		this->e_month = e_month;
		this->b_data = b_data;
		this->e_data = e_data;
		this->b_hour = b_hour;
		this->e_hour = e_hour;
		this->b_min = b_min;
		this->e_min = e_min;
		this->price = price;
		this->type = type;
		this->sum = sum;
		this->n = n;
	}

	string getFlight()
	{
		return flg;
	}

	string getB_place()
	{
		return b_place;
	}

	string getE_place()
	{
		return e_place;
	}

	int getB_month()
	{
		return b_month;
	}

	int getE_month()
	{
		return e_month;
	}

	int getB_data()
	{
		return b_data;
	}

	int getE_data()
	{
		return e_data;
	}

	int getB_hour()
	{
		return b_hour;
	}

	int getE_hour()
	{
		return e_hour;
	}

	int getB_min()
	{
		return b_min;
	}

	int getE_min()
	{
		return e_min;
	}

	int getSum()
	{
		return sum;
	}

	int getN()
	{
		return n;
	}

	string getType()
	{
		return type;
	}

	int getPrice()
	{
		return price;
	}

	void setFlight(string flg)
	{
		this->flg = flg;
	}

	void setB_place(string b_place)
	{
		this->b_place = b_place;
	}

	void setE_place(string e_place)
	{
		this->e_place = e_place;
	}

	void setB_month(int b_month)
	{
		this->b_month = b_month;
	}

	void setE_month(int e_month)
	{
		this->e_month = e_month;
	}

	void setB_data(int b_data)
	{
		this->b_data = b_data;
	}

	void setE_data(int e_data)
	{
		this->e_data = e_data;
	}

	void setB_hour(int b_hour)
	{
		this->b_hour = b_hour;
	}

	void setE_hour(int e_hour)
	{
		this->e_hour = e_hour;
	}

	void setB_min(int b_min)
	{
		this->b_min = b_min;
	}

	void setE_min(int e_min)
	{
		this->e_min = e_min;
	}

	void setSum(int sum)
	{
		this->sum = sum;
	}

	void setN(int n)
	{
		this->n = n;
	}

	void setType(string type)
	{
		this->type = type;
	}

	void getPrice(int price)
	{
		this->price = price;
	}

	void showInfo()
	{
		cout << "flght:" << flg << endl <<  b_place << "---->" << e_place << endl << b_month << "." << b_data << " " << b_hour << ":" << b_min << "--" << e_month<< "." << e_data << " " << e_hour << ":" << e_min << endl << "price:" << price << endl <<"type:" << type << endl << "seat:" << n << "/" << sum << endl;
	}
};
/*
int main()
{
	string flg = "CZ3841";
	string b_place = "???";
	string e_place = "??";
	int b_month = 5;
	int e_month = 5;
	int b_data = 8;
	int e_data = 8;
	int b_hour = 9;
	int e_hour = 11;
	int b_min = 45;
	int e_min = 20;
	int price = 990;
	string type = "???737";
	int sum = 500;
	int n = 24;

	Flight f(flg, b_place, e_place, b_month, b_data, b_hour, b_min, e_month, e_data, e_hour, e_min, price, type, sum, n);
	f.showInfo();

	return 0;
}
*/