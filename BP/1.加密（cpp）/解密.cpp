#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	cout << "����������ļ���(��:\"out.txt\")" << endl;
		
	char name[50];
	ifstream infile;
	cin>>name;

	infile.open(name,ios::in);          //�û�ָ����Ҫ���ܵ��ļ�

	ofstream outfile("in.txt");        //�ļ��������
	char ch;
	char k;

	while( infile.get( ch ) )     //�����Կո񣬹ʲ��� >> ��ȡ
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
