// Librarian.h: interface for the Librarian class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARIAN_H__E437CC4D_E26C_48B4_AB8A_BCC7B5C9D8E6__INCLUDED_)
#define AFX_LIBRARIAN_H__E437CC4D_E26C_48B4_AB8A_BCC7B5C9D8E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"

class Librarian : public Object  
{
private:
	long ID;//��ʶ
	char name[20];
	char passwd[9];//����
public:
	Librarian(long ID,char *name);
	char login();
	virtual ~Librarian()
	{

	}

};
Librarian::Librarian(long ID,char *name)
{
	this->ID=ID;
	strcpy(this->name,name);
	strcpy(this->passwd,"abc");
}

char Librarian::login()//��¼
{
	char pw[9];
	for(int i=0;i<3;++i)//����������������
	{
		cout<<"Enter  password:";
		cin>>pw;
		if(strcmp(pw,passwd)==0)
			return 'X';
	}
	cout<<"Login fail��"<<endl;
	return 'E';
}
#endif // !defined(AFX_LIBRARIAN_H__E437CC4D_E26C_48B4_AB8A_BCC7B5C9D8E6__INCLUDED_)
