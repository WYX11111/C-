#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,j,k,min,brief,n;
	int D[20][20];

	cout << "���������";
	cin >> n;

	int b=(int)pow(2,n-1);
  	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>D[i][j];
		
	int ** Route = new int *[n];
	
	int ** Mat = new int *[n];
  	
	for(i=0;i<n;i++)
	{
		Route[i] = new int[b];
		Mat[i] = new int [b];
	}
	
	for(i=0;i<b;i++)
		for(j=0;j<n;j++)
		{
			Route[j][i] = -1;
			Mat[j][i] = -1;
		}

	for(i=0;i<n;i++)//��ʼ����0�� 
		Route[i][0] = D[i][0];
  	
	for(i=1;i<b-1;i++)
		for(j=1;j<n;j++)//���ν��е�i�ε��� 
			if( ((int)pow(2,j-1) & i) == 0)//�Ӽ�V[j]������i 
			{
				min=999;
				for(k=1;k<n;k++)
				if( (int)pow(2,k-1) & i )
				{
					brief = D[j][k] + Route[k][i-(int)pow(2,k-1)]; 
					if(brief < min)
					{
						min = brief;
						Route[j][i] = min;
						Mat[j][i] = k;//�ֲ����ž���
					}
				}    
			}
	min=999;
  	for(k=1;k<n;k++)
	{
		brief = D[0][k] + Route[k][b - 1 - (int)pow(2,k-1)];
		if(brief < min)
		{
			min = brief;
			Route[0][b-1] = min;//���Ž�
			Mat[0][b-1] = k;
		}
	}
	cout << "���·�����ȣ�" << Route[0][b-1]<< endl;//���·������
	cout << "���·����" << "0";
	for(i=b-1,j=0; i>0; )
	{
		j = Mat[j][i];
		i = i - (int)pow(2,j-1);
		cout << "->" <<j;
	}
	cout << "->" << "0" << endl;
	return 0;
}