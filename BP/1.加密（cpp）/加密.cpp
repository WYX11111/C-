#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	int k;
	cout << "��ѡ��" << endl << "1.�����ļ�" << endl << "2.����ԭ�ļ���" << endl;
	cin >> k;
	if (k == 1)
	{
		cout << "����������ļ���(��:\"in.txt\")" << endl;
		
		char name[50];
		ifstream infile;
		cin>>name;

		infile.open(name,ios::in);          //�û�ָ����Ҫ���ܵ��ļ�

		ofstream outfile("out.txt");        //�ļ������������
		char ch;
		char k;

		while( infile.get( ch ) )     //�����Կո񣬹ʲ��� >> ��ȡ
		{
			k = rand();
			ch = ch ^ k;
			outfile.put(ch);
		}
		infile.close();
		outfile.close();
		printf("�����ѱ�����out.txt�ļ���\n");
	}

	if (k == 2)
	{
		cout << "�������������,�س�����" << endl;
		char ch;
		char k;

		ofstream outfile("out.txt");        //�ļ������������
	
		//��ջ�����
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
		printf("�����ѱ�����out.txt�ļ���\n");
	}
	return 0;
}
