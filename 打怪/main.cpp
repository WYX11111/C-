#include <iostream>
#include <string>
#include <time.h>

using namespace std;

enum Tag {D, O, S};

//生物类
class Creature{
private:
	string name;  //名称
	char tag;     //标志
	int hp;       //生命
	int at;       //攻击力
	int g;        //金币
public:
	void setInfo(string n, char t, int h, int a, int go)  //set全部信息
	{
		name = n;
		tag = t;
		hp = h;
		at = a;
		g = go;
	}

	void setName(string n)  //set姓名
	{
		name = n;
	}

	string getName()        //get姓名
	{
		return name;
	}

	void setTag(char t)     //set标志
	{
		tag = t;
	}

	char getTag()           //get标志
	{
		return tag;
	}

	void setHp(int h)       //set生命值
	{
		hp = h;
	}

	int getHp()             //get生命值
	{
		return hp;
	}

	void setAt(int a)       //set攻击力
	{
		at = a;
	}

	int getAt()             //get攻击力
	{
		return at;
	}

	void setG(int go)       //set金币
	{
		g = go;
	}

	int getG()              //get金币
	{
		return g;
	}

	void hurt(int t)        //计算伤害
	{
		hp -= t;
	}

	void addg(int d)         //金币累加
	{
		g += d;
	}

	int cheak_hp()           //检验生命归零
	{
		if(hp <= 0)
			return 1;
		else return 0;
	}
};

//怪物类 继承自 生物类
class Monster :public Creature
{
public:
	Monster(enum Tag T): Creature()    //构造函数完成怪物种类的区别
	{
		switch(T)
		{
			case D:
				Creature::setInfo("dragon", 'D', 20, 4 ,100);
				break;
			case O:
				Creature::setInfo("orc", 'O', 4, 2 ,25);
				break;
			case S:
				Creature::setInfo("slime", 'S', 1, 1 ,10);
				break;
		}
	}
};

//玩家类 继承自 生物类
class Player: public Creature
{
private:
	int le;     //等级
public:
	Player(): Creature()
	{
		string n;
		Creature::setInfo("@",'P', 10, 1, 0);
		le = 1;
		cout << "Enter your name:";
		cin >> n;
		setName(n);
	}

	void setLe(int l)   //set等级
	{
		le = l;
	}

	int getLe()          //get等级
	{
		return le;
	}
};

void fight(Player &player)   //fight函数用于控制游戏流程
{
	int mon;    //用于随机产生怪物种类
	Monster *monster;
	enum Tag T;
	char temp;

	cout << "Welcome, " << player.getName() << endl;
	srand((unsigned)time(0));

	while(player.getHp() > 0 && player.getLe() < 20)
	{
		
		cout << "*********************************************************"<< endl;
		cout << "等级" << player.getLe() << "生命" << player.getHp()<< "金币" << player.getG() << endl;
		cout << "*********************************************************"<< endl;


		mon = rand() % 3;     //随机生成怪物种类
		if(mon == 0)
		{
			T = D;
			monster = new Monster(T);
		}
		if(mon == 1)
		{
			T = O;
			monster = new Monster(T);
		}
		if(mon == 2)
		{
			T = S;
			monster = new Monster(T);
		}

		cout << "You have encountered a " << monster->getName() << "(" << monster->getTag() << ")" << endl;
		//遇敌  怪物生命值归零或玩家生命值归零则结束一次遇敌
		while(monster->getHp() > 0 && player.getHp() > 0)
		{
			cout << "(R)un or (F)ight:";  //选择逃跑或战斗

			cin >> temp;

			if(temp == 'r' || temp == 'R')  //逃跑
			{
				int k = rand() % 2;         //50%概率逃跑成功
				
				if (k == 0)                 //逃跑成功就结束一次遇敌
				{
					cout << "You successfully fled." <<endl;
					break;
				}
				else
					cout << "You faile to fled." <<endl;
			}

			if(temp == 'f' || temp == 'F')  //战斗
			{
				monster->hurt(player.getAt());   //怪物受到伤害
				cout << "You hit the " << monster->getName() << " " << player.getAt() << " damage." << endl;

				if(monster->getHp() <= 0)   //如果怪物生命值归零就结束一次遇敌，且玩家战斗力、等级以及金币增加
				{
					player.setLe(player.getLe() + 1);  //等级上升
					player.setG(player.getG() + monster->getG()); //金币增加
					player.setAt(player.getAt() + 1);  //攻击力增加
					cout << "You found " << monster->getG() << " " << "gold." << endl;
					break;
				}
			}
			player.hurt(monster->getAt());  //若怪物没有被打败，则攻击玩家
			cout << "The " << monster->getName() << " hit you " << monster->getAt() << " damage." << endl;
		}
	}
	if(player.getHp() <= 0)  //玩家生命值归零，游戏结束
	{
		cout << endl << "You Lose!!!!" << endl;
		cout << "等级" << player.getLe() << "金币" << player.getG() << endl;
	}
	else //玩家升至20级游戏结束
	{
		cout << endl << "You Win!!!!" << endl;
		cout << "金币" << player.getG() << endl;
	}
}
int main()
{
	Player player;
	fight(player);
	return 0;
}