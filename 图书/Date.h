// Date.h: interface for the Date class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATE_H__C112A571_1A69_4CF5_84DD_D15F67804EFC__INCLUDED_)
#define AFX_DATE_H__C112A571_1A69_4CF5_84DD_D15F67804EFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"
#include<ctime>

class Date : public Object  
{
public:
	int year, month, day;
	Date();
	Date(int y,int m,int d);
	virtual ~Date()
	{
		
	}
	int GetYear();
	int GetMonth();
	int GetDay();
	int DayOfMonth(int y, int m);
	bool IsLeapyear();
	bool IsLeapyear(int y);
	void display();
};

Date::Date()//���캯������ʼ��Ĭ�ϵ�����
{
	time_t curtime=time(NULL);
	tm tim=*localtime(&curtime);//tm �ṹ��
	day=tim.tm_mday;//һ�����е����ڣ���Χ[1-31]
	month=tim.tm_mon+1;//�·ݣ���һ�¿�ʼ����Χ[0-11]
	year=tim.tm_year+1900;//��ݣ���ֵ����ʵ�����-1900
}
Date::Date(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;//�����ڸ�ֵ
	if((y<=0)||(m<=0||m>12)||(d<=0||d>DayOfMonth(y,m)))//�ж���Ч����
	{
		std::cout<<"Invalid data,data has been set to 1900-1-1"<<std::endl;
		year=1900;
		month=day=1;
	}
}

int Date::DayOfMonth(int y, int m)//����һ���µ�����
{
	int d = 0;//����
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		d = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		d = 30;
		break;
	case 2:
		d = 28 + IsLeapyear(y);
		break;
	}
	return d;
}

int Date::GetYear()
{
	return year;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetDay()
{
	return day;
}

bool Date::IsLeapyear()//�ж�����
{
	if((year%4 == 0 && year%100 != 0) || year %400 == 0)
		return true;
	else
		return false;
}

bool Date::IsLeapyear(int y)
{
	if((y % 4 == 0 && y % 100!=0)||y % 400 == 0)
		return true;
	else 
		return false;
}

void Date::display()//�������ֵ
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}

#endif // !defined(AFX_DATE_H__C112A571_1A69_4CF5_84DD_D15F67804EFC__INCLUDED_)
