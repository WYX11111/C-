#include <iostream>
#include "Creature.cpp"
#include <string>

using namespace std;

class Player: public Creature
{
private:
	int le;
public:
	Player(): Creature()
	{
		string n;
		Creature::setInfo("@",'P', 10, 1, 0);
		le = 0;
		cout << "Enter your name:";
		cin >> n;
		setName(n);
	}
};
