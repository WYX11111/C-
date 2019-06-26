#include "Pair.cpp"

template <class T>
class StringValuePair: public Pair<string, T>    //继承自Pair，StringValuePair关键字类型为string
{
public:
	StringValuePair(string k,T v) :Pair<string,T>(k, v) {}
};
