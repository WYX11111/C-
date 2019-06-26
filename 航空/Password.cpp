#define USE_OPENSS

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include <cstdlib>
#include "Passenger.cpp"
using namespace std;

#include "openssl/sha.h"

vector<string> W;

string sha256(const string str)
{
	char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::string NewString = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(buf,"%02x",hash[i]);
        NewString = NewString + buf;
    }
	return NewString;
}

void save_w()
{
	ofstream KFile("Password.txt");

	for(vector<string>::iterator it = W.begin(); it != W.end(); it++)
		KFile << (*it) << endl;
}
//注册账号
Passenger* signin(string ID, string password)
{
	char s[128];
	int i;
	srand(time(NULL));
	for(i=0;i<100;i++)
	{
		do
		{
			s[i] = rand()%128;
		}
		while(!isprint(s[i]));
	}
	string salt(s);  //生成长度为128的salt

	string name;
	string nationality;
	string num;
	string tel;

	cout << "输入姓名:";
	cin >> name;

	cout << "输入国籍:";
	cin >> nationality;
	
	cout << "输入护照:";
	cin >> num;

	cout << "输入手机号:";
	cin >> tel;   //输入个人信息

	int n = 3;    //设置迭代的最大次数为三次

	Passenger *p = new Passenger(name, num, nationality, tel);
	password += salt;

	string key;
	for(i = 0; i < n; i++)
	{
		key = sha256(password);  //生成密钥
		password = key;
	}

	ofstream kFile; //保存文件
	kFile.open("Password.txt", ios::app);

	kFile << endl << ID << endl;
	kFile << salt << endl;
	kFile << key << endl;
	kFile << num << endl;
	kFile << n << endl;
	return p;
}
//登陆
string login(string ID, string password)
{
	ifstream kFile;
	kFile.open("Password.txt");
	char str[305];
	string re = " ";
	//打开储存密码信息的文件
	while (!kFile.eof())
	{
		kFile.getline(str,300);
		string id(str);
		W.push_back(id);
		if(id.compare(ID) == 0)   //当ID号匹配成功
		{
			kFile.getline(str,300);
			string salt(str);
			W.push_back(salt);

			kFile.getline(str,300);
			string key(str);

			kFile.getline(str,300);
			string num(str);
			
			kFile.getline(str,300);
			int n = atoi(str);

			password += salt;

			string k;

			//根据文件信息确定要迭代的次数
			for(int i = 0; i < n-1; i++)
			{
				k = sha256(password);
				password = k;
			}

			string ke = sha256(password);
			if(ke.compare(key) == 0) //密码匹配成功 将新的迭代次数和密钥储存进文件
			{
				
				if(n == 1)
				{
					n = 4;
					for(int i = 0; i < n-1; i++)
					{
						k = sha256(password);
						password = k;
					}
				}

				W.push_back(k);
				W.push_back(num);

				itoa(n-1,str,10);
				string sn(str);
				
				W.push_back(sn);
				re = num;
			}
			else
			{
				cout << "密码错误" << endl;
				exit (0);
			}
		}
	}
	kFile.close();
	if(re.compare(" ") != 0)
	{
		save_w();
		return re;
	}
	else 
	{
		cout << "账号不存在";
		exit (0);
	}
}
/*
int main()
{
	std::string x = "hello world";
	cout << sha256(x) << endl;
    return 0;
}*/
