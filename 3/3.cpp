#include "io.h"     //����io.hͷ�ļ�

int main()
{
	int a = readNumber();   //����io.cpp���readNumber()��������һ������
	int b = readNumber();
	writeAnswer(a + b);     //��ӡ������
	return 0;
}