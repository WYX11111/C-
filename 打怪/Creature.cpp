#include <iostream>
#include <string>

using namespace std;

class Creature{
private:
	string name;
	char tag;
	int hp;
	int at;
	int g;
public:
	void setInfo(string n, char t, int h, int a, int go)
	{
		name = n;
		tag = t;
		hp = h;
		at = a;
		g = go;
	}

	void setName(string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}

	void setTag(char t)
	{
		tag = t;
	}

	char getTag()
	{
		return tag;
	}

	void setHp(int h)
	{
		hp = h;
	}

	int getHp()
	{
		return hp;
	}

	void setAt(int a)
	{
		at = a;
	}

	int getAt()
	{
		return at;
	}

	void setG(int go)
	{
		g = go;
	}

	int getG()
	{
		return g;
	}

	void hurt(int t)
	{
		hp -= t;
	}

	void addg(int d)
	{
		g += d;
	}

	int cheak_hp()
	{
		if(hp <= 0)
			return 1;
		else return 0;
	}
};