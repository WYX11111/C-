// BookDate.h: interface for the BookDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKDATE_H__36BA58EF_BB64_4F01_BF47_6DB3094A3810__INCLUDED_)
#define AFX_BOOKDATE_H__36BA58EF_BB64_4F01_BF47_6DB3094A3810__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"

class BookDate : public Object  
{
private:
	long BookID;//图书条形码
	char name[40];
	State state;//图书的状态enum State{READER,LIB,SHELF}
	long PIN;//读者号码

public:
	BookData();
	BookData(long BookID,char *name,State state=SHELF,long PIN=0);
	virtual ~BookDate();
	const long GetID();
	const char *GetName();
	long GetPIN();
	void ShowData();
	void SetID(long BookID);
	void SetState(State state);
	void SetPIN(long PIN);
};

#endif // !defined(AFX_BOOKDATE_H__36BA58EF_BB64_4F01_BF47_6DB3094A3810__INCLUDED_)
