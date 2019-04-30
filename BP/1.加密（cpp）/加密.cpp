#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	int k;
	cout << "请选择" << endl << "1.加密文件" << endl << "2.输入原文加密" << endl;
	cin >> k;
	if (k == 1)
	{
		cout << "输入待加密文件名(如:\"in.txt\")" << endl;
		
		char name[50];
		ifstream infile;
		cin>>name;

		infile.open(name,ios::in);          //用户指定需要加密的文件

		ofstream outfile("out.txt");        //文件接收输出密文
		char ch;
		char k;

		while( infile.get( ch ) )     //不忽略空格，故不用 >> 读取
		{
			k = rand();
			ch = ch ^ k;
			outfile.put(ch);
		}
		infile.close();
		outfile.close();
		printf("密文已保存于out.txt文件中\n");
	}

	if (k == 2)
	{
		cout << "输入待加密文字,回车结束" << endl;
		char ch;
		char k;

		ofstream outfile("out.txt");        //文件接收输出密文
	
		//清空缓冲区
		cin.clear();
		cin.ignore();
		
		cin >> noskipws >> ch;
		
		while(ch != '\n')
		{
			k = rand();
			ch = ch ^ k;
			outfile.put(ch);
			cin >> noskipws >> ch;
		}
		printf("密文已保存于out.txt文件中\n");
	}
	return 0;
}
