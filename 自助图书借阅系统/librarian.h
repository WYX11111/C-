class Librarian : public Object  
{
private:
	long ID;
	char name[20];
	char passwd[9];
public:
	Librarian(long ID,char *name) :ID(ID)
	{
		strcpy(this->name,name);
		strcpy(this->passwd,"abc");
	}

	char login()
	{
		char pw[9];
		for(int i=0;i<3;++i)
		{
			cout<<"Enter  password:";
			cin>>pw;
			if(strcmp(pw,passwd)==0)
			return 'X';
		}
		cout<<"Login fail£¡"<<endl;
		return 'E';
	}
};
