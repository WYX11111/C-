#include <iostream>

using namespace std;

double readNumber()    //����һ��������
{
    double a;
	cout << "Enter a double value:";
    cin >> a;
    return a;
}

void calculate(double a, double b)  //�ж������������
{
	char c;
	cout << "Enter one kind of the following: +,-,*or/ :";
	cin >> c;         //���������
	switch (c)        //�ж������
	{
	case '+':
		cout << a << "+" << b << "is" << a + b; 
		break;
	case '-':
		cout << a << "-" << b << "is" << a - b;
		break;
	case '*':
		cout << a << "*" << b << "is" << a * b;
		break;
	case '/':
		if (b == 0)    //���ǳ���Ϊ0
			cout << "error";
		else 
			cout << a << "/" << b << "is" << a / b;
		break;
	default:           //�����������������
		cout << "error";
	}
}

int main()
{
	double a = readNumber();
	double b = readNumber();
	calculate(a, b);
	return 0;
}