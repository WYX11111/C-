#include<ctime>
using namespace std;

class Date : public Object  
{
	int year, month, day;
	int DayOfMonth(int y, int m) const;

public:
	Date()
	{
		time_t curtime = time(NULL);
		tm tim=*localtime(&curtime);
		day=tim.tm_mday;
		month=tim.tm_mon+1;
		year=tim.tm_year+1900;
	}
	
	Date(int y,int m,int d)
		:year(y),month(m),day(d)
	{
		if((y<=0)||(m<=0||m>12)||(d<=0||d>DayOfMonth(y,m)))
		{
			cout<<"Invalid data,data has been set to 1900-1-1"<<endl;
			year=1900;
			month=day=1;
		}
	}

	virtual ~Date()
	{

	}

	int DayOfMonth(int y, int m)
	{
		int d = 0;
		switch (m)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				d = 31;
				break;
			case 4: case 6: case 9: case 11:
				d = 30;
				break;
			case 2:
				d = 28 + IsLeapyear(y);
				break;
		}
		return d;
	}

	int GetYear() const
	{
		return year;
	}

	int GetMonth() const
	{
		return month;
	}

	int GetDay() const
	{
		return day;
	}

	bool IsLeapyear() const
	{
		if((year%4 == 0 && year%100 != 0) || year %400 == 0)
			return true;
		else
			return false;
	}

	bool IsLeapyear(const int y) const
	{
		if((y % 4 == 0 && y % 100!=0)||y % 400 == 0)
			return true;
		else 
			return false;
	}

	void display() const
	{
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
};
