// Database.h: interface for the Database class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__142BA0A3_9FAF_490C_BF84_20B091ADF03A__INCLUDED_)
#define AFX_DATABASE_H__142BA0A3_9FAF_490C_BF84_20B091ADF03A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Object.h"
#include <iostream>
#include <map>
#include "Date.h"

using namespace std;


template<class T>
class Database  :public Object
{
private:
	fstream File;
	char FileName[40];//�ļ���
	long FileLen,rec_size;//�ļ����ȣ���¼��С
	typedef map<long,T,less<long> > mtype;//����һ����������mtype,����ֵ
	mtype RecMap;//��¼���ݿ�
public:
	Database();
	Database(char *FileName);
	void Insert(T &);
	void Delete(long);
	T *Query(long);
	T *QueryName(char *);
	void SaveMap();
	void ShowAllData();
	virtual ~Database()
	{

	}
};

template<class T>
Database<T>::Database()
{

}

//�����ݿ⣬��������
template<class T>
Database<T>::Database(char* FileName)
{
	strcpy(this->FileName,FileName);
	File.open(FileName,ios::in|ios::binary);
	rec_size=sizeof(T);
	if(File.is_open()){
		File.seekg(0,ios::end);//���������ļ���λ��ios����end����ʾ�������Ľ���λ��
		if((FileLen=File.tellg())>0)//tellg()���ص�ǰ��λָ���λ�ã�Ҳ�������������Ĵ�С��
		{
			T Object;
			File.seekg(0,ios::beg);//ios::beg��ʾ�������Ŀ�ʼλ��
			do{
				File.read((char*)&Object,rec_size);
				RecMap.insert(mtype::value_type(Object.GetID(),Object));
			}while(File.tellg()<FileLen);
		}
		File.close();
	}
}


//�����ļ�
template<class T>
void Database<T>::SaveMap()
{
	mtype::const_iterator iter;//C++Ϊÿ���������Ͷ�����һ����Ϊconst_iterator������,������ֻ�����ڶ�ȡ�����ڵ�Ԫ��,�����ܸı���ֵ
	T Object;
	File.open(FileName,ios::out|ios::binary|ios::trunc);
	for(iter=RecMap.begin();iter!=RecMap.end();++iter)
		File.write((char*)&iter->second,rec_size);
	File.close();
}

template<class T>
void Database<T>::Insert(T &Object)
{
	RecMap.insert(mtype::value_type(Object.GetID(),Object));//�������ࣿ��
}


//��ѯ
template<class T>
T *Database<T>::Query(long ObjID)
{
	mtype::iterator iter;//ָ��
	iter=RecMap.find(ObjID);
	if(iter==RecMap.end())
	{
		cout<<ObjID<<"not found��"<<endl;
		return NULL;
	}
	else
		return &(iter->second);
}


//��ѯ����
template<class T>
T *Database<T>::QueryName(char *ObjName)
{
	mtype::iterator iter;
	for(iter=RecMap.begin();iter!=RecMap.end();++iter)//����һ������������ָ�����������һ��Ԫ�ص���һλ��
	{
		if(strstr((iter->second).GetName(),ObjName)!=NULL)//strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ�
		{
			cout<<"find a name"<<(iter->second).GetName()<<endl;
			return&(iter->second);
		}
	}
	cout<<ObjName<<"in"<<typeid(T).name()<<"not found��"<<endl;//typeid���ڷ���ָ���������ָ�����ʵ������
	return NULL;
}


//ɾ��һ����¼
template<class T>
void Database<T>::Delete(long ObjID)
{
	Query(ObjID);
	RecMap.erase(ObjID);
}

//��ʾ��������
template<class T>
void Database<T>::ShowAllData()
{
	mtype::iterator iter;
	T Object;
	cout<<"Data in "<<typeid(T).name()<<"��"<<endl;
	for(iter=RecMap.begin();iter!=RecMap.end();++iter){
		(iter->second).ShowData();//BookData���ж�����ShowData()
	}
}


#endif // !defined(AFX_DATABASE_H__142BA0A3_9FAF_490C_BF84_20B091ADF03A__INCLUDED_)
