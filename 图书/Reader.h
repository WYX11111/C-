// Reader.h: interface for the Reader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READER_H__8B55A576_7884_4A48_B093_5B6667AE6BB4__INCLUDED_)
#define AFX_READER_H__8B55A576_7884_4A48_B093_5B6667AE6BB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"

class Reader : public Object  
{
private:
	long PIN;//读者借书卡号
	long BookID[3];//书车中存储的书号
	int num;//书车中数的数目
public:
	Reader(long PIN = 0,int num = 0)
	{
		this->PIN=PIN;
		this->num=num;
	}
	int AddBook(long BookID);//将书选入书车中
	long CheckOut();//借书
	void ShowCart();
	int GetNum();
	virtual ~Reader();
};
int Reader::AddBook(long BookID)//将书选入书车中
{
	if(num<LIMIT)
	{
		this->BookID[num]=BookID;
		cout<<"Book "<<BookID<<" added!"<<endl;
		num++;
		return 1;
	}
	else
		cout<<"Cart full！"<<endl;//书车已满
	return 0;
}

long Reader::CheckOut()
{
	--num;
	return BookID[num];//顺序??
}

void Reader::ShowCart()
{
	for(int i=0;i<num;i++)
		cout<<BookID[i]<<endl;
}

int Reader::GetNum()
{
	return num;
}

Reader::~Reader()
{

}


#endif // !defined(AFX_READER_H__8B55A576_7884_4A48_B093_5B6667AE6BB4__INCLUDED_)
