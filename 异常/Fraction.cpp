#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction
{
private:
	double numerator;    //����
	double denominator;  //��ĸ

public:
	Fraction(double a, double b) //���캯��  a������,b����ĸ
	{
		try
		{
			if(b == 0)
			{
				throw runtime_error(""); //�׳��쳣
			}
			else
			{
				numerator = a;
				denominator = b;
				cout << a << "/" << b << endl;  //����Ϸ� ��ӡ
			}
		}
		catch(exception err)  //�����쳣
		{
			cout << "����Ƿ�" << endl;
		}
	}
};

int main()
{
	int a, b;
	cout << "������ӷ�ĸ:";
	cin >> a >> b;
	Fraction f(a,b);
	return 0;
}