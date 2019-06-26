class BookData : public Object  
{
private:
	long BookID;
	char name[40];
	State state;
	long PIN;

public:
	BookData()
	{
		BookID = 0;
		PIN = 0;
	}

	BookData(long BookID,char *name,State state=SHELF,long PIN=0)
	{
		SetID(BookID);
		SetName(name);
		SetState(state);
		SetPIN(PIN);
	}

	const long GetID()
	{
		return BookID;
	}
	
	const char *GetName()
	{
		return name;
	}

	State GetState()
	{
		return state;
	}

	long GetPIN()
	{
		return PIN;
	}

	void ShowData()
	{
		cout<<BookID<<'\t'<<name<<'\t'<<state<<'\t'<<PIN<<endl;
	}
	void SetID(long BookID)
	{
		this->BookID=BookID;
	}

	void SetName(const char *i_name)
	{
		strcpy(name,i_name);
	}

	void SetState(State state)
	{
		this->state=state;
	}

	void SetPIN(long PIN)
	{
		this->PIN=PIN;
	}
};