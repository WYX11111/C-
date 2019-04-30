#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

class IntArray    //����������
{
public:
	//����ָ�룬���鳤��
	int *a;       
	int SIZE;

	friend ostream& operator << (ostream&,IntArray&); //��Ԫ�������������<<�����غ���������

	IntArray()//�޲ι���
	{
		SIZE = 0;
		a = NULL;
	}

	IntArray(int n)//�вι���
	{
		SIZE = n;
		a = new int[n];
	}
	
	int& operator[](int i)//�����±�"[]"�����
	{
		assert(a[i]);     //�ж��Ƿ�Խ��
		return a[i];
	}

	IntArray(const IntArray& b) //�������캯��(���������ڴ�ռ�)
	{
		SIZE = b.SIZE;
		a = new int[SIZE];
		memcpy(a, b.a, SIZE * sizeof(int));
	}
 
	void operator=(const IntArray& b)//����"="�����
	{
		this->SIZE = b.SIZE;
		this->a = b.a;
	}
};

ostream& operator << (ostream& output,IntArray& c) //�����������<<�����غ���
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