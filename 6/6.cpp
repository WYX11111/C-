#include <iostream>
#include <string>

using namespace std;

struct student
{
	string name;
	int grade;
};//����ṹ�� ���������ͳɼ�

int main()
{
	int n, k;
	cin >> n;  //��������
	student *s;
	s = new student[n];  //�������������ڴ�
	for(k = 0; k < n; k++) //������Ϣ
	{
		cin >> s[k].name;
		cin >> s[k].grade;
	}
	for(k = 0; k < n; k++)//��ӡ��Ϣ
	{
		cout << s[k].name << " got a grade of " << s[k].grade << endl;
	}
	return 0;
}