#include<iostream>

using namespace std;

int main()
{
	int i,j,k;
	int n;
	int D[20][20];

	cout << "���������";
	cin>>n;
	
	int *s = new int[n];    //��¼������˳��
	
	for(i=0; i<n; i++) //������������֮���˳�� 
		for(j=0; j<n; j++)
			cin>>D[i][j];

	int sum = 0;//��¼����
	int Dtemp = 999;
	int l;
	int flag = 0;
	i = 1;

	s[0] = 0;//�����һ�������Ѿ������� 

	do{
		k = 1;
		Dtemp = 999;
		do
		{
			l = 0;flag = 0;
			do
			{
				if(s[l] == k)
				{
					flag = 1;
					break;
				}
				else l++;
			}while(l<i);
			
			if(flag == 0 && D[k][s[i-1]] <Dtemp)
			{
				j = k;//��������i-1��̵ĳ��� 
				Dtemp = D[k][s[i-1]];//������̵ľ��� 
			}
			k++;
		}while(k<n);

		s[i] = j;//�����ʵĳ��м�¼
		sum+=Dtemp;//�����ۼ� 
		i++; 
	}while(i<n);
	
	
	sum+=D[0][j];
	
	cout << "��̾���Ϊ��" << sum << endl;
	cout<<"���·��Ϊ��";
	
	for(i=0; i<n; i++)
	{
		cout<<s[i]<<"->";
	}
	cout << "->0" << endl;
	return 0;
}