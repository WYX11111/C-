#include "StringValuePair.cpp"

int main()
{
	StringValuePair<int> svp("Hello",5);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}