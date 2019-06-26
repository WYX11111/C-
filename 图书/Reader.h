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
	long PIN;//���߽��鿨��
	long BookID[3];//�鳵�д洢�����
	int num;//�鳵��������Ŀ
public:
	Reader(long PIN = 0,int num = 0)
	{
		this->PIN=PIN;
		this->num=num;
	}
	int AddBook(long BookID);//����ѡ���鳵��
	long CheckOut();//����
	void ShowCart();
	int GetNum();
	virtual ~Reader();
};
int Reader::AddBook(long BookID)//����ѡ���鳵��
{
	if(num<LIMIT)
	{
		this->BookID[num]=BookID;
		cout<<"Book "<<BookID<<" added!"<<endl;
		num++;
		return 1;
	}
	else
		cout<<"Cart full��"<<endl;//�鳵����
	return 0;
}

long Reader::CheckOut()
{
	--num;
	return BookID[num];//˳��??
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
