// ReaderData.h: interface for the ReaderData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READERDATA_H__309A9923_429E_45D7_8C63_F4D8F91F88B8__INCLUDED_)
#define AFX_READERDATA_H__309A9923_429E_45D7_8C63_F4D8F91F88B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"
#include "Date.h"
#include "ReaderData.h"

class ReaderData : public Object  
{
protected:
	long PIN;//����֤��
	char name[20];
	long BookList[LIMIT];//��������������,ͼ���б�
	Date BorrowDate[LIMIT];
	int num;//����ͼ����

public:
	ReaderData();
	ReaderData(int PIN,char *name);
	virtual ~ReaderData();
	void SetID(long PIN){this->PIN=PIN;};
	void SetName(char *i_name){strcpy(name,i_name);};
	long GetID(){return PIN;};
	char * GetName(){return name;};
	int GetNum(){return num;};
	long BorrowBook(long);
	void ShowData();
	long ReturnBook(long);
};
ReaderData::ReaderData()
{
	PIN=0;
	num=0;
	for(int i=0; i<LIMIT ;++i)
		BookList[i]=0;
}

ReaderData::ReaderData(int PIN,char *name)
{
	//Date BorrowDate[3];//��������??
	SetID(PIN);
	SetName(name);
	num=0;
	for(int i=0;i<LIMIT;++i)
		BookList[i]=0;
}

ReaderData::~ReaderData()
{

}

long ReaderData::BorrowBook(long BookID)
{
	for(int i=0;i<LIMIT;++i)
		if(BookList[i]==0)
		{
			BookList[i]=BookID;
			BorrowDate[i]=Date();//?
			num++;
			return BookID;
		}
	cout<<"Book reach the limit��"<<endl;//ͼ�鳬�����޶�
	return 0;
}

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
	cout<<PIN<<"\t"<<name<<endl;
	for(int i=0;i<LIMIT;i++)
	{
		if(BookList[i])
		{
			cout<<i+1<<":"<<BookList[i]<<"\t";
			BorrowDate[i].display();
		}
	}
}
#endif // !defined(AFX_READERDATA_H__309A9923_429E_45D7_8C63_F4D8F91F88B8__INCLUDED_)
