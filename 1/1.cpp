#include <iostream>

using namespace std;

int readNumber()          //����һ������
{
    int a;
    cin >> a;
    return a;
}

void writeAnswer(int a)   //��ӡһ������
{
    cout << a;
}

int main()
{
	int a = readNumber();   //����readNumber()�����һ������
	int b = readNumber();   //����readNumber()����ڶ�������
	writeAnswer(a + b);     //��ӡ������
	return 0;
}