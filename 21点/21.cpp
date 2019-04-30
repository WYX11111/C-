#include <iostream>
#include <time.h>

using namespace std;

class Card{             //Card 用于保存单张牌的信息
private:
	int card_number;    //牌面大小
	int card_color;     //花色
public:
	Card()
	{
		this->card_number = 0;
		this->card_color = 0;
	}

	Card(int card_number, int card_color)      //构造函数
	{
		this->card_number = card_number;
		this->card_color = card_color;
	}

	void set_card(int card_number, int card_color)   //牌面信息可设置，方便洗牌
	{
		this->card_number = card_number;
		this->card_color = card_color;
	}

	//取得牌面信息
	int get_card_number()
	{
		return card_number;
	}

	int get_card_color()
	{
		return card_color;
	}

	void show_card()             //展示牌面信息
	{
		switch(this->card_color){
		case 1:
			cout << "红心 "; break;
		case 2:
			cout << "黑桃 "; break;
		case 3:
			cout << "方片 "; break;
		case 4:
			cout << "梅花 "; break;
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

class Deck{       //用于保存一副牌的所有信息，包括洗牌等函数
public:
	Card *card;   //存放52张牌的信息
public:
	Deck()        //Deck构造函数，产生Deck对象时，设置52张牌的信息（未洗牌）
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

	void rand_number()    //洗牌函数
	{
		int i;
		int card_number;
		int card_color;
		int value;

		srand((unsigned)time(0));

		for(i = 0; i < 52; i++)   //依次将1到52号位置的牌与随机取到的某一位置的牌进行交换
		{
			value = rand() % 52;

			card_number = card[i].get_card_number();
			card_color = card[i].get_card_color();

			card[i].set_card(card[value].get_card_number(), card[value].get_card_color());
			
			card[value].set_card(card_number, card_color);
		}
	}

	int get_sum(int a[12]) //求和函数，用一个数组储存取到的牌的值，用于求和
	{
		int i, num = 0;    //num用于储存‘A’的个数
		int sum = 0;
		for(i = 0; a[i]; i++)
		{
			if(a[i] != 1)  //牌面不是 A J Q K 直接求和，J Q K 算做10
			{
				if(a[i] < 11)
					sum += a[i];
				else if(a[i] > 10)
					sum += 10;
			}

			else           //记录牌面是A的个数
				num++;
		}

		while(num--)       //牌面是A 求和不超过11 A算11 否则算1
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

		cout << "您已拿到:" << endl;               //第一张发给庄家  第二张第三张发给玩家 作为底牌
		
		card[i].show_card();
		a[i-1] = card[i].get_card_number();        //用数组a记录玩家抽到的牌
		cout << endl;
		i++;

		card[i].show_card();
		a[i-1] = card[i].get_card_number();
		cout <<endl;
		i++;

		k = this->get_sum(a);                       //调用求和函数，用k记录玩家手牌的和

		cout << "牌的和为" << k;

		cout << endl << "是否要牌(1: 要 2:不要)";
		cin >> t;
		int h_foot = 0;                             //用h数组记录除了底牌以外玩家的手牌，h_foot记录除了底牌以外玩家的手牌数
		
		while(t == 1)                               //玩家要牌
		{
			
			cout << "您拿到:" << endl;
			card[i].show_card();
			a[i-1] = card[i].get_card_number();
			h[h_foot++] = a[i-1];
			cout << endl;
			i++;
			k = this->get_sum(a);
			
			if(k > 21)                              //若玩家爆牌立即判定为输
			{
				cout << "牌的和为" << k << endl;
				cout << endl << "You lose" << endl;
				return;
			}
			
			else
				cout << "牌的和为" << k;
			
			cout << endl << "是否要牌(1: 要 2:不要)";
			cin >> t;
		}

		if(t == 2)                                  //玩家不要牌，庄家开始要牌
		{
			int h_sum = this->get_sum(h);
			cout << endl <<"庄家拿到:" << endl;
			
			card[0].show_card();                    //庄家底牌
			b[j] = card[0].get_card_number();       //用数组b记录庄家抽到的牌
			cout << endl;
			j++;

			m = this->get_sum(b);                   
			cout << "庄家牌的和为" << m << endl;
			
			if(lev == 1)                            //easy难度庄家不管玩家手牌，只要手牌的和小于17就要牌（容易爆牌）
			{
				while(m < 17)
				{
					cout << "庄家拿到:" << endl;
					card[i].show_card();
					b[j] = card[i].get_card_number();
					i++;
					j++;
					cout << endl;

					m = this->get_sum(b);
					cout << "庄家牌的和为" << m <<endl;
					if(m > 21)
					{
						cout << endl << "You win" << endl;
						return;
					}
				}
			}

			if(lev == 2)                             //hard难度，对玩家手牌（除了底牌）判断，当玩家牌的数值较小时，有效防止爆牌
			{
				if(i == 3)
				{
					while(m < 12)
					{
						cout << "庄家拿到:" << endl;
						card[i].show_card();
						b[j] = card[i].get_card_number();
						i++;
						j++;
						cout << endl;

						m = this->get_sum(b);
						cout << "庄家牌的和为" << m <<endl;
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
						cout << "庄家拿到:" << endl;
						card[i].show_card();
						b[j] = card[i].get_card_number();
						i++;
						j++;
						cout << endl;

						m = this->get_sum(b);
						cout << "庄家牌的和为" << m <<endl;
						if(m > 21)
						{
							cout << endl << "You win" << endl;
							return;
						}
					}
				}
			}

			if(lev == 3)   //very hard难度 系统作弊 可看到下一张要抽的牌，绝对不会爆牌
			{
				while(1)
				{
					b[j] = card[i].get_card_number(); //系统判断下一张
					j++;
					m = this->get_sum(b);
					if( m > 21)                       //如果爆牌则不抽
					{
						b[j-1] = 0;
						m = this->get_sum(b);
						break;
					}

					cout << "庄家拿到:" << endl;
					card[i].show_card();
					i++;
					cout << endl;
					cout << "庄家牌的和为" << m <<endl;
				}
			}

			cout << endl;
		    //m记录着庄家抽到的所有牌的和，k记录着玩家抽到的所有牌的和，若无人爆牌，最后进行比较
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
		poker.rand_number();  //每次游戏前洗牌
		cout << "选择难度:" << endl << "1-easy" << endl << "2-hard" << endl << "3-very hard" << endl;
		cin >> t;

		if(t == 1 || t == 2 || t == 3)
			poker.game(t);
		else
			cout << "error" << endl;

		cout << "是否重新开始(1:重新开始 2:结束游戏)" << endl;
		
		cin >> t;
		if(t == 2)
			break;
		cout << endl;
	}
	return 0;
}