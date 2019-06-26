// BookData.h: interface for the BookData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKDATA_H__103E8E66_EA92_40B4_9E35_FEEA9743AE83__INCLUDED_)
#define AFX_BOOKDATA_H__103E8E66_EA92_40B4_9E35_FEEA9743AE83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"

class BookData : public Object  
{
private:
	long BookID;//图书条形码
	char name[40];
	State state;//图书的状态enum State{READER,LIB,SHELF}
	long PIN;//读者号码

public:
	BookData();
	//BookData(long BookID,char *name,State state=SHELF,long PIN=0)
	BookData(long BookID,char *name,State state=SHELF,long PIN=0)
	{
		SetID(BookID);
		SetName(name);
		SetState(state);
		SetPIN(PIN);
	}
	virtual ~BookData()
	{

	}
	const long GetID();
	const char *GetName();
	State GetState()
	{
		return state;
	}
	long GetPIN();
	void ShowData();
	void SetID(long BookID);
	void SetName(char *i_name);
	void SetState(State state);
	void SetPIN(long PIN);
};
BookData::BookData()
{
	BookID=0;
	PIN=0;
}

const long BookData::GetID()
{
	return BookID;
}

const char *BookData::GetName()
{
	return name;
}

long BookData::GetPIN()
{
	return PIN;
}

void BookData::ShowData()
{
	cout<<BookID<<'\t'<<name<<'\t'<<state<<'\t'<<PIN<<endl;
}
void BookData::SetID(long BookID)
{
	this->BookID=BookID;
}

void BookData::SetName(char *i_name)
{
	strcpy(name,i_name);
}

void BookData::SetState(State state)
{
	this->state=state;
}

void BookData::SetPIN(long PIN)
{
	this->PIN=PIN;
}
#endif // !defined(AFX_BOOKDATA_H__103E8E66_EA92_40B4_9E35_FEEA9743AE83__INCLUDED_)
