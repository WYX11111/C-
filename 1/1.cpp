#include <iostream>

using namespace std;

int readNumber()          //输入一个整数
{
    int a;
    cin >> a;
    return a;
}

void writeAnswer(int a)   //打印一个整数
{
    cout << a;
}

int main()
{
	int a = readNumber();   //调用readNumber()输入第一个数字
	int b = readNumber();   //调用readNumber()输入第二个数字
	writeAnswer(a + b);     //打印两数和
	return 0;
}