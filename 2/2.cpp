#include "io.cpp"         //导入io.cpp

int main()
{
	int a = readNumber(); //调用io.cpp里的readNumber()函数输入一个整数
	int b = readNumber();
	writeAnswer(a + b);   //打印两数和
	return 0;
}