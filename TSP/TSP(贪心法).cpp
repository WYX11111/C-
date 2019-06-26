#include<iostream>

using namespace std;

int main()
{
	int i,j,k;
	int n;
	int D[20][20];

	cout << "顶点个数：";
	cin>>n;
	
	int *s = new int[n];    //记录遍历的顺序
	
	for(i=0; i<n; i++) //输入两个城市之间的顺序 
		for(j=0; j<n; j++)
			cin>>D[i][j];

	int sum = 0;//记录距离
	int Dtemp = 999;
	int l;
	int flag = 0;
	i = 1;

	s[0] = 0;//代表第一个城市已经被访问 

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
				j = k;//保留距离i-1最短的城市 
				Dtemp = D[k][s[i-1]];//保留最短的距离 
			}
			k++;
		}while(k<n);

		s[i] = j;//将访问的城市记录
		sum+=Dtemp;//距离累加 
		i++; 
	}while(i<n);
	
	
	sum+=D[0][j];
	
	cout << "最短距离为：" << sum << endl;
	cout<<"最短路径为：";
	
	for(i=0; i<n; i++)
	{
		cout<<s[i]<<"->";
	}
	cout << "->0" << endl;
	return 0;
}