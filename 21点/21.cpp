#include <iostream>
#include <time.h>

using namespace std;

class Card{             //Card ���ڱ��浥���Ƶ���Ϣ
private:
	int card_number;    //�����С
	int card_color;     //��ɫ
public:
	Card()
	{
		this->card_number = 0;
		this->card_color = 0;
	}

	Card(int card_number, int card_color)      //���캯��
	{
		this->card_number = card_number;
		this->card_color = card_color;
	}

	void set_card(int card_number, int card_color)   //������Ϣ�����ã�����ϴ��
	{
		this->card_number = card_number;
		this->card_color = card_color;
	}

	//ȡ��������Ϣ
	int get_card_number()
	{
		return card_number;
	}

	int get_card_color()
	{
		return card_color;
	}

	void show_card()             //չʾ������Ϣ
	{
		switch(this->card_color){
		case 1:
			cout << "���� "; break;
		case 2:
			cout << "���� "; break;
		case 3:
			cout << "��Ƭ "; break;
		case 4:
			cout << "÷�� "; break;
		}
		if(this->card_number == 1)
			cout << 'A';
		else if(this->card_number <= 10)
			cout << this->card_number;
		else if(this->card_number == 11)
			cout << 'J';
		else if(this->card_number == 12)
			cout << 'Q';
		else if(this->card_number == 13)
			cout << 'K';
	}
};

class Deck{       //���ڱ���һ���Ƶ�������Ϣ������ϴ�ƵȺ���
public:
	Card *card;   //���52���Ƶ���Ϣ
public:
	Deck()        //Deck���캯��������Deck����ʱ������52���Ƶ���Ϣ��δϴ�ƣ�
	{
		card = new Card[52];
		for(int i = 0; i < 13; i++)
		{
			card[i * 4].set_card(i+1, 1);
			card[i * 4 + 1].set_card(i+1, 2);
			card[i * 4 + 2].set_card(i+1, 3);
			card[i * 4 + 3].set_card(i+1, 4);
		}
	}

	void rand_number()    //ϴ�ƺ���
	{
		int i;
		int card_number;
		int card_color;
		int value;

		srand((unsigned)time(0));

		for(i = 0; i < 52; i++)   //���ν�1��52��λ�õ��������ȡ����ĳһλ�õ��ƽ��н���
		{
			value = rand() % 52;

			card_number = card[i].get_card_number();
			card_color = card[i].get_card_color();

			card[i].set_card(card[value].get_card_number(), card[value].get_card_color());
			
			card[value].set_card(card_number, card_color);
		}
	}

	int get_sum(int a[12]) //��ͺ�������һ�����鴢��ȡ�����Ƶ�ֵ���������
	{
		int i, num = 0;    //num���ڴ��桮A���ĸ���
		int sum = 0;
		for(i = 0; a[i]; i++)
		{
			if(a[i] != 1)  //���治�� A J Q K ֱ����ͣ�J Q K ����10
			{
				if(a[i] < 11)
					sum += a[i];
				else if(a[i] > 10)
					sum += 10;
			}

			else           //��¼������A�ĸ���
				num++;
		}

		while(num--)       //������A ��Ͳ�����11 A��11 ������1
		{
			if(sum < 11)
				sum += 11;
			else
				sum += 1;
		}

		return sum;
	}

	void game(int lev)
	{
		int i = 1, j = 0, t, k, m;
		int a[12] = {0}, b[12]={0}, h[12] = {0};

		cout << "�����õ�:" << endl;               //��һ�ŷ���ׯ��  �ڶ��ŵ����ŷ������ ��Ϊ����
		
		card[i].show_card();
		a[i-1] = card[i].get_card_number();        //������a��¼��ҳ鵽����
		cout << endl;
		i++;

		card[i].show_card();
		a[i-1] = card[i].get_card_number();
		cout <<endl;
		i++;

		k = this->get_sum(a);                       //������ͺ�������k��¼������Ƶĺ�

		cout << "�Ƶĺ�Ϊ" << k;

		cout << endl << "�Ƿ�Ҫ��(1: Ҫ 2:��Ҫ)";
		cin >> t;
		int h_foot = 0;                             //��h�����¼���˵���������ҵ����ƣ�h_foot��¼���˵���������ҵ�������
		
		while(t == 1)                               //���Ҫ��
		{
			
			cout << "���õ�:" << endl;
			card[i].show_card();
			a[i-1] = card[i].get_card_number();
			h[h_foot++] = a[i-1];
			cout << endl;
			i++;
			k = this->get_sum(a);
			
			if(k > 21)                              //����ұ��������ж�Ϊ��
			{
				cout << "�Ƶĺ�Ϊ" << k << endl;
				cout << endl << "You lose" << endl;
				return;
			}
			
			else
				cout << "�Ƶĺ�Ϊ" << k;
			
			cout << endl << "�Ƿ�Ҫ��(1: Ҫ 2:��Ҫ)";
			cin >> t;
		}

		if(t == 2)                                  //��Ҳ�Ҫ�ƣ�ׯ�ҿ�ʼҪ��
		{
			int h_sum = this->get_sum(h);
			cout << endl <<"ׯ���õ�:" << endl;
			
			card[0].show_card();                    //ׯ�ҵ���
			b[j] = card[0].get_card_number();       //������b��¼ׯ�ҳ鵽����
			cout << endl;
			j++;

			m = this->get_sum(b);                   
			cout << "ׯ���Ƶĺ�Ϊ" << m << endl;
			
			if(lev == 1)                            //easy�Ѷ�ׯ�Ҳ���������ƣ�ֻҪ���Ƶĺ�С��17��Ҫ�ƣ����ױ��ƣ�
			{
				while(m < 17)
				{
					cout << "ׯ���õ�:" << endl;
					card[i].show_card();
					b[j] = card[i].get_card_number();
					i++;
					j++;
					cout << endl;

					m = this->get_sum(b);
					cout << "ׯ���Ƶĺ�Ϊ" << m <<endl;
					if(m > 21)
					{
						cout << endl << "You win" << endl;
						return;
					}
				}
			}

			if(lev == 2)                             //hard�Ѷȣ���������ƣ����˵��ƣ��жϣ�������Ƶ���ֵ��Сʱ����Ч��ֹ����
			{
				if(i == 3)
				{
					while(m < 12)
					{
						cout << "ׯ���õ�:" << endl;
						card[i].show_card();
						b[j] = card[i].get_card_number();
						i++;
						j++;
						cout << endl;

						m = this->get_sum(b);
						cout << "ׯ���Ƶĺ�Ϊ" << m <<endl;
						if(m > 21)
						{
							cout << endl << "You win" << endl;
							return;
						}
					}
				} 
				else
				{
					while(m < h_sum + 12)
					{
						cout << "ׯ���õ�:" << endl;
						card[i].show_card();
						b[j] = card[i].get_card_number();
						i++;
						j++;
						cout << endl;

						m = this->get_sum(b);
						cout << "ׯ���Ƶĺ�Ϊ" << m <<endl;
						if(m > 21)
						{
							cout << endl << "You win" << endl;
							return;
						}
					}
				}
			}

			if(lev == 3)   //very hard�Ѷ� ϵͳ���� �ɿ�����һ��Ҫ����ƣ����Բ��ᱬ��
			{
				while(1)
				{
					b[j] = card[i].get_card_number(); //ϵͳ�ж���һ��
					j++;
					m = this->get_sum(b);
					if( m > 21)                       //��������򲻳�
					{
						b[j-1] = 0;
						m = this->get_sum(b);
						break;
					}

					cout << "ׯ���õ�:" << endl;
					card[i].show_card();
					i++;
					cout << endl;
					cout << "ׯ���Ƶĺ�Ϊ" << m <<endl;
				}
			}

			cout << endl;
		    //m��¼��ׯ�ҳ鵽�������Ƶĺͣ�k��¼����ҳ鵽�������Ƶĺͣ������˱��ƣ������бȽ�
			if(m < k)
			{
				cout << endl << "You win" << endl;
					return;
			}
			else if(m > k)
			{
				cout << "You lose" << endl;
					return;
			}
			else if(m == k)
			{
				cout << "Draw" << endl;
					return;
			}
		}
	}
};

int main ()
{
	Deck poker;
	int t;
	
	while(1)
	{
		poker.rand_number();  //ÿ����Ϸǰϴ��
		cout << "ѡ���Ѷ�:" << endl << "1-easy" << endl << "2-hard" << endl << "3-very hard" << endl;
		cin >> t;

		if(t == 1 || t == 2 || t == 3)
			poker.game(t);
		else
			cout << "error" << endl;

		cout << "�Ƿ����¿�ʼ(1:���¿�ʼ 2:������Ϸ)" << endl;
		
		cin >> t;
		if(t == 2)
			break;
		cout << endl;
	}
	return 0;
}