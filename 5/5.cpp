#include <iostream>

using namespace std;

enum item {medicine=1, torch, arrow}; //ö������

int contTotalltems(enum item menu[])
{
	int a = 0;
	for(a = 0; menu[a] <=3 && menu[a] >= 1; a++);  //�ж��Ƿ�Ϊö�������е�ֵ
	return a;
}

int main()
{
	enum item menu[17];      //��ʼ��Ʒ��
	menu[0] = menu[1] = medicine;
	menu[2] = menu[3] = menu[4] = menu[5] = menu[6] = torch;
	menu[7] = menu[8] = menu[9] = menu[10] = menu[11] = menu[12] = menu[13] = menu[14] = menu[15] = menu[16] = arrow;

	int n = contTotalltems(menu);
	cout << n;
	return 0;	
}