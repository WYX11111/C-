#include <iostream>
#include <string>
#include <time.h>

using namespace std;

enum Tag {D, O, S};

//������
class Creature{
private:
	string name;  //����
	char tag;     //��־
	int hp;       //����
	int at;       //������
	int g;        //���
public:
	void setInfo(string n, char t, int h, int a, int go)  //setȫ����Ϣ
	{
		name = n;
		tag = t;
		hp = h;
		at = a;
		g = go;
	}

	void setName(string n)  //set����
	{
		name = n;
	}

	string getName()        //get����
	{
		return name;
	}

	void setTag(char t)     //set��־
	{
		tag = t;
	}

	char getTag()           //get��־
	{
		return tag;
	}

	void setHp(int h)       //set����ֵ
	{
		hp = h;
	}

	int getHp()             //get����ֵ
	{
		return hp;
	}

	void setAt(int a)       //set������
	{
		at = a;
	}

	int getAt()             //get������
	{
		return at;
	}

	void setG(int go)       //set���
	{
		g = go;
	}

	int getG()              //get���
	{
		return g;
	}

	void hurt(int t)        //�����˺�
	{
		hp -= t;
	}

	void addg(int d)         //����ۼ�
	{
		g += d;
	}

	int cheak_hp()           //������������
	{
		if(hp <= 0)
			return 1;
		else return 0;
	}
};

//������ �̳��� ������
class Monster :public Creature
{
public:
	Monster(enum Tag T): Creature()    //���캯����ɹ������������
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

//����� �̳��� ������
class Player: public Creature
{
private:
	int le;     //�ȼ�
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

	void setLe(int l)   //set�ȼ�
	{
		le = l;
	}

	int getLe()          //get�ȼ�
	{
		return le;
	}
};

void fight(Player &player)   //fight�������ڿ�����Ϸ����
{
	int mon;    //�������������������
	Monster *monster;
	enum Tag T;
	char temp;

	cout << "Welcome, " << player.getName() << endl;
	srand((unsigned)time(0));

	while(player.getHp() > 0 && player.getLe() < 20)
	{
		
		cout << "*********************************************************"<< endl;
		cout << "�ȼ�" << player.getLe() << "����" << player.getHp()<< "���" << player.getG() << endl;
		cout << "*********************************************************"<< endl;


		mon = rand() % 3;     //������ɹ�������
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
		//����  ��������ֵ������������ֵ���������һ������
		while(monster->getHp() > 0 && player.getHp() > 0)
		{
			cout << "(R)un or (F)ight:";  //ѡ�����ܻ�ս��

			cin >> temp;

			if(temp == 'r' || temp == 'R')  //����
			{
				int k = rand() % 2;         //50%�������ܳɹ�
				
				if (k == 0)                 //���ܳɹ��ͽ���һ������
				{
					cout << "You successfully fled." <<endl;
					break;
				}
				else
					cout << "You faile to fled." <<endl;
			}

			if(temp == 'f' || temp == 'F')  //ս��
			{
				monster->hurt(player.getAt());   //�����ܵ��˺�
				cout << "You hit the " << monster->getName() << " " << player.getAt() << " damage." << endl;

				if(monster->getHp() <= 0)   //�����������ֵ����ͽ���һ�����У������ս�������ȼ��Լ��������
				{
					player.setLe(player.getLe() + 1);  //�ȼ�����
					player.setG(player.getG() + monster->getG()); //�������
					player.setAt(player.getAt() + 1);  //����������
					cout << "You found " << monster->getG() << " " << "gold." << endl;
					break;
				}
			}
			player.hurt(monster->getAt());  //������û�б���ܣ��򹥻����
			cout << "The " << monster->getName() << " hit you " << monster->getAt() << " damage." << endl;
		}
	}
	if(player.getHp() <= 0)  //�������ֵ���㣬��Ϸ����
	{
		cout << endl << "You Lose!!!!" << endl;
		cout << "�ȼ�" << player.getLe() << "���" << player.getG() << endl;
	}
	else //�������20����Ϸ����
	{
		cout << endl << "You Win!!!!" << endl;
		cout << "���" << player.getG() << endl;
	}
}
int main()
{
	Player player;
	fight(player);
	return 0;
}