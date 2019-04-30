#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

class IntArray    //整形数组类
{
public:
	//数组指针，数组长度
	int *a;       
	int SIZE;

	friend ostream& operator << (ostream&,IntArray&); //友元函数，运算符“<<”重载函数的申明

	IntArray()//无参构造
	{
		SIZE = 0;
		a = NULL;
	}

	IntArray(int n)//有参构造
	{
		SIZE = n;
		a = new int[n];
	}
	
	int& operator[](int i)//重载下标"[]"运算符
	{
		assert(a[i]);     //判断是否越界
		return a[i];
	}

	IntArray(const IntArray& b) //拷贝构造函数(单独开辟内存空间)
	{
		SIZE = b.SIZE;
		a = new int[SIZE];
		memcpy(a, b.a, SIZE * sizeof(int));
	}
 
	void operator=(const IntArray& b)//重载"="运算符
	{
		this->SIZE = b.SIZE;
		this->a = b.a;
	}
};

ostream& operator << (ostream& output,IntArray& c) //定义运算符“<<”重载函数
{
	for(int i = 0; i < c.SIZE - 1; i++)
		output << c.a[i] << " ";
	output << c.a[c.SIZE-1];
	return output;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
	return a;
}

int main()
{
	IntArray a = fillArray();
	cout << a << '\n';
	IntArray b(1);
	a = a;
	b = a;
	cout << b << '\n';

	IntArray c(b);
	c[0] = 10;
	cout << c << '\n';
	return 0;
}