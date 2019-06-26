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
	char FileName[40];//文件名
	long FileLen,rec_size;//文件长度，记录大小
	typedef map<long,T,less<long> > mtype;//定义一个关联容器mtype,键、值
	mtype RecMap;//记录数据库
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

//打开数据库，插入数据
template<class T>
Database<T>::Database(char* FileName)
{
	strcpy(this->FileName,FileName);
	File.open(FileName,ios::in|ios::binary);
	rec_size=sizeof(T);
	if(File.is_open()){
		File.seekg(0,ios::end);//对输入流文件定位，ios：：end：表示输入流的结束位置
		if((FileLen=File.tellg())>0)//tellg()返回当前定位指针的位置，也代表着输入流的大小。
		{
			T Object;
			File.seekg(0,ios::beg);//ios::beg表示输入流的开始位置
			do{
				File.read((char*)&Object,rec_size);
				RecMap.insert(mtype::value_type(Object.GetID(),Object));
			}while(File.tellg()<FileLen);
		}
		File.close();
	}
}


//保存文件
template<class T>
void Database<T>::SaveMap()
{
	mtype::const_iterator iter;//C++为每种容器类型定义了一种名为const_iterator的类型,该类型只能用于读取容器内的元素,但不能改变其值
	T Object;
	File.open(FileName,ios::out|ios::binary|ios::trunc);
	for(iter=RecMap.begin();iter!=RecMap.end();++iter)
		File.write((char*)&iter->second,rec_size);
	File.close();
}

template<class T>
void Database<T>::Insert(T &Object)
{
	RecMap.insert(mtype::value_type(Object.GetID(),Object));//？？多余？？
}


//查询
template<class T>
T *Database<T>::Query(long ObjID)
{
	mtype::iterator iter;//指针
	iter=RecMap.find(ObjID);
	if(iter==RecMap.end())
	{
		cout<<ObjID<<"not found！"<<endl;
		return NULL;
	}
	else
		return &(iter->second);
}


//查询名字
template<class T>
T *Database<T>::QueryName(char *ObjName)
{
	mtype::iterator iter;
	for(iter=RecMap.begin();iter!=RecMap.end();++iter)//返回一个迭代器，它指向容器的最后一个元素的下一位置
	{
		if(strstr((iter->second).GetName(),ObjName)!=NULL)//strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串
		{
			cout<<"find a name"<<(iter->second).GetName()<<endl;
			return&(iter->second);
		}
	}
	cout<<ObjName<<"in"<<typeid(T).name()<<"not found！"<<endl;//typeid用于返回指针或引用所指对象的实际类型
	return NULL;
}


//删除一条记录
template<class T>
void Database<T>::Delete(long ObjID)
{
	Query(ObjID);
	RecMap.erase(ObjID);
}

//显示所有数据
template<class T>
void Database<T>::ShowAllData()
{
	mtype::iterator iter;
	T Object;
	cout<<"Data in "<<typeid(T).name()<<"："<<endl;
	for(iter=RecMap.begin();iter!=RecMap.end();++iter){
		(iter->second).ShowData();//BookData类中定义了ShowData()
	}
}


#endif // !defined(AFX_DATABASE_H__142BA0A3_9FAF_490C_BF84_20B091ADF03A__INCLUDED_)
