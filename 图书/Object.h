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

const int LIMIT=3;//��������޶�
enum State{READER,LIB,SHELF};//ͼ���״̬���ڶ��ߴ�����ͼ��ݣ�δ�ϼܣ���������ϣ�

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
