#include "Pair.cpp"

template <class T>
class StringValuePair: public Pair<string, T>    //�̳���Pair��StringValuePair�ؼ�������Ϊstring
{
public:
	StringValuePair(string k,T v) :Pair<string,T>(k, v) {}
};
