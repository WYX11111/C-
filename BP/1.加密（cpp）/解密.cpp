#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	cout << "输入待解密文件名(如:\"out.txt\")" << endl;
		
	char name[50];
	ifstream infile;
	cin>>name;

	infile.open(name,ios::in);          //用户指定需要解密的文件

	ofstream outfile("in.txt");        //文件接收输出
	char ch;
	char k;

	while( infile.get( ch ) )     //不忽略空格，故不用 >> 读取
	{
		k = rand();
		ch = ch ^ k;
		cout << ch;
		outfile.put(ch);
	}
	infile.close();
	outfile.close();

	return 0;
}
