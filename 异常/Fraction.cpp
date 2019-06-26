#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction
{
private:
	double numerator;    //分子
	double denominator;  //分母

public:
	Fraction(double a, double b) //构造函数  a做分子,b做分母
	{
		try
		{
			if(b == 0)
			{
				throw runtime_error(""); //抛出异常
			}
			else
			{
				numerator = a;
				denominator = b;
				cout << a << "/" << b << endl;  //输入合法 打印
			}
		}
		catch(exception err)  //处理异常
		{
			cout << "输入非法" << endl;
		}
	}
};

int main()
{
	int a, b;
	cout << "输入分子分母:";
	cin >> a >> b;
	Fraction f(a,b);
	return 0;
}