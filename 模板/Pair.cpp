#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Pair
{
public:
	T1 key;      //�ؼ���
	T2 value;    //ֵ
	Pair(T1 k, T2 v):key(k), value(v) {};    //���캯����ʹ��ģ�壬��T1���͵�k����key����T2���͵�v����value
	T1 first() const  //���عؼ���
	{
		return key;
	}

	T2 second() const  //����ֵ
	{
		return value;
	}

};
