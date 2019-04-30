#include <iostream>
#include <string>

using namespace std;

struct student
{
	string name;
	int grade;
};//定义结构体 包含姓名和成绩

int main()
{
	int n, k;
	cin >> n;  //输入人数
	student *s;
	s = new student[n];  //根据人数分配内存
	for(k = 0; k < n; k++) //输入信息
	{
		cin >> s[k].name;
		cin >> s[k].grade;
	}
	for(k = 0; k < n; k++)//打印信息
	{
		cout << s[k].name << " got a grade of " << s[k].grade << endl;
	}
	return 0;
}