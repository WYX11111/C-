#include <iostream>
#include "Creature.cpp"
#include <string>

using namespace std;

enum Tag {D, O, S};

class Monster :public Creature
{
public:
	Monster(enum Tag T): Creature()
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
