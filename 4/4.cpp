#include <iostream>

using namespace std;

double readNumber()    //输入一个浮点数
{
    double a;
	cout << "Enter a double value:";
    cin >> a;
    return a;
}

void calculate(double a, double b)  //判断运算符并计算
{
	char c;
	cout << "Enter one kind of the following: +,-,*or/ :";
	cin >> c;         //输入运算符
	switch (c)        //判断运算符
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
		if (b == 0)    //考虑除数为0
			cout << "error";
		else 
			cout << a << "/" << b << "is" << a / b;
		break;
	default:           //考虑输入运算符有误
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