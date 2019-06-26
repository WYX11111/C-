// Object.h: interface for the Object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__8714628F_DE88_41D9_BCDC_F84F78464063__INCLUDED_)
#define AFX_OBJECT_H__8714628F_DE88_41D9_BCDC_F84F78464063__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;

const int LIMIT=3;//读书借阅限额
enum State{READER,LIB,SHELF};//图书的状态（在读者处、在图书馆（未上架）、在书架上）

class Object  
{
public:
	Object();
	virtual ~Object();

};
Object::Object()
{

}

Object::~Object()
{

}

#endif // !defined(AFX_OBJECT_H__8714628F_DE88_41D9_BCDC_F84F78464063__INCLUDED_)
