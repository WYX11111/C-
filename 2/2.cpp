#include "io.cpp"         //����io.cpp

int main()
{
	int a = readNumber(); //����io.cpp���readNumber()��������һ������
	int b = readNumber();
	writeAnswer(a + b);   //��ӡ������
	return 0;
}