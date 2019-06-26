#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Pair
{
public:
	T1 key;      //关键字
	T2 value;    //值
	Pair(T1 k, T2 v):key(k), value(v) {};    //构造函数，使用模板，将T1类型的k赋给key，将T2类型的v赋给value
	T1 first() const  //返回关键字
	{
		return key;
	}

	T2 second() const  //返回值
	{
		return value;
	}

};
