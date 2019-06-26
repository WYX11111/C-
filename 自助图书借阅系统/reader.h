class Reader : public Object  
{
private:
	long PIN;
	long BookID[LIMIT];
	int num;
public:
	Reader(long PIN = 0,const int num = 0)
	{
		this->PIN=PIN;
		this->num=num;
	}

	int AddBook(const long BookID)
	{
		if(num<LIMIT)
		{
			this->BookID[num]=BookID;
			cout<<"Book "<<BookID<<" added!"<<endl;
			num++;
			return 1;
		}
		else
			cout<<"Cart full£¡"<<endl;//Êé³µÒÑÂú
		return 0;
	}

	long CheckOut()
	{
		--num;
		return BookID[num];
	}

	void ShowCart()
	{
		for(int i=0;i<num;i++)
			cout<<BookID[i]<<endl;
	}
	
	int GetNum()
	{
		return num;
	}
};