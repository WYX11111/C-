#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	
	ifstream file1;
	ifstream file2;
	ifstream file3;

	file1.open("in2.txt",ios::in);
	file2.open("out1.txt",ios::in);
	file3.open("out2.txt",ios::in);    //分别打开两个密文及其中一个密文对应的原文
	
	char ch1, ch2, ch3;

	while(file2.get( ch2 ))         //假设两段原文为C1、C2 对应的两段密文为 M1、M2 密钥为k，C1 ^ k = M1 C2 ^ k = M2,则 C1^C2 = M1^M2
	{
		file1.get( ch1 );
		file3.get( ch3 );
		ch2 = ch3 ^ ch2 ^ ch1;
		cout << ch2;
	}

	file1.close();
	file2.close();
	file3.close();
	
	return 0;
}