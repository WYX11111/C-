#include "Password.cpp"

using namespace std;

class User
{
public:
	vector<Passenger*> P;   //用于记录乘客文件中的所有乘客信息
	vector<Flight*> F;      //用于记录航班文件中的所有航班信息
public:
	User()  //构造函数（将两个文件里的所有信息写入vector里）
	{
		char str[105];
		ifstream pfile("Passenger.txt");
		ifstream ffile("Flight.txt");

		if (! pfile.is_open())
    	{
    		cout << "Error opening file";
    	}

    	while (!pfile.eof())   //读入乘客信息
    	{
    		pfile.getline(str,100);
    		
    		pfile.getline(str,100);
			string name(str);

			pfile.getline(str,100);
			string passport(str);
			
			pfile.getline(str,100);
			string nationality(str);
			
			pfile.getline(str,100);
			string tel(str);
    		
    		P.push_back(new Passenger(name,passport,nationality,tel));

    		pfile.getline(str,100);
    		while(str[0] != '*')
    		{
    			string flg(str);
    			P.back()->addFlight(flg);
    			pfile.getline(str,100);
    		}
    	}

		if (! ffile.is_open())
    	{
    		cout << "Error opening file";
    	}

    	while (!ffile.eof())  //读入航班信息
    	{
    		ffile.getline(str,100);
    		string flg(str);

    		ffile.getline(str,100);
			string b_place(str);

			ffile.getline(str,100);
			string e_place(str);

			ffile.getline(str,100);
			int b_month = atoi(str);

			ffile.getline(str,100);
			int b_data = atoi(str);

			ffile.getline(str,100);
			int b_hour = atoi(str);
    		
			ffile.getline(str,100);
			int b_min = atoi(str);

			ffile.getline(str,100);
			int e_month = atoi(str);

			ffile.getline(str,100);
			int e_data = atoi(str);

			ffile.getline(str,100);
			int e_hour = atoi(str);
    		
			ffile.getline(str,100);
			int e_min = atoi(str);

			ffile.getline(str,100);
			int price = atoi(str);
 
			ffile.getline(str,100);
			string type(str);

			ffile.getline(str,100);
			int sum = atoi(str);

			ffile.getline(str,100);
			int n = atoi(str);
    		F.push_back(new Flight(flg, b_place, e_place, b_month, b_data, b_hour, b_min, e_month, e_data, e_hour, e_min, price, type, sum, n));
    	}
	}

	void show_all_flight()  //显示所有航班（管理员功能）
	{
		for(vector<Flight*>::iterator fit = F.begin(); fit != F.end(); fit++)  //遍历航班vector里的所有航班
		{
			(*fit)->showInfo();
			cout << endl;
		}
	}

	void check_flight(string fl)  //查询某一航班（根据航班号查询）
	{
		for(vector<Flight*>::iterator it = F.begin(); it != F.end(); it++)
		{
			if((*it)->getFlight().compare(fl) == 0)
			{
				(*it)->showInfo();
				break;
			}
		}
	}

	void show_one_passenger(string pass)  //显示乘客信息
	{
		for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
		{
			if((*it)->getNum().compare(pass) == 0)
			{
				(*it)->showInfo();
				for(vector<string>::iterator its = (*it)->flight.begin(); its != (*it)->flight.end(); its++)
				{
					(*it)->showFlight((*its), F);
				}
				break;
			}
		}
	}

	void show_all_passenger()  //显示所有乘客信息（管理员功能）
	{
		for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
		{
			(*it)->showInfo();
			for(vector<string>::iterator its = (*it)->flight.begin(); its != (*it)->flight.end(); its++)
			{
				(*it)->showFlight((*its), F);
			}
		}
	}

	void book_flight(string pass, string fl)//预约航班
	{
		int t;
		for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
		{
			if((*it)->getNum().compare(pass) == 0)  //首先确认乘客
			{
				for(vector<Flight*>::iterator its = F.begin(); its != F.end(); its++)
				{
					if((*its)->getFlight().compare(fl) == 0)      //再确认有这班航班
					{
						(*its)->showInfo();                       //显示航班信息，确认支付
						cout << "确认支付" << (*its)->getPrice() << "元?(按“1”确认)";
						cin >> t;
						if(t == 1)
						{
							int k = (*it)->addFlight(fl);
							if(k == 1)
								(*its)->setN((*its)->getN() + 1);
						}
						return ;
					}
				}
				cout << "无此航班!" << endl;
			}
		}
	}

	void remove_flight(string pass, string fl)//取消预约
	{
		for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
		{
			if((*it)->getNum().compare(pass) == 0)   //找到某一航班，调用乘客类中的remove函数取消预约
			{
				(*it)->removeFlight(fl);
				for(vector<Flight*>::iterator its = F.begin(); its != F.end(); its++)//找到这一航班，将已预约人数-1
				{
					if((*its)->getFlight().compare(fl) == 0)
						(*its)->setN((*its)->getN() - 1);
				}
				break;
			}
		}
	}

	int check_data_error(int month, int day, int hour, int min)   //检查日期格式是否正确
	{
		if(month < 1 || month > 12 || day < 0 || day > 31 || hour < 0 || hour > 24 || min < 0 || min > 60)
			return 0;
		if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return 0;
		if(month == 2 && day >28)
			return 0;
		else
			return 1;
	}

	int check_data(int b_month, int b_day, int b_hour, int b_min, int e_month, int e_day, int e_hour, int e_min)  //检查出发时间和到达时间的先后
	{
		int b_sum = 0, e_sum = 0;
		int i;
		int j = check_data_error(b_month, b_day, b_hour, b_min);
		int k = check_data_error(e_month, e_day, e_hour, e_min);
		if(j == 0 || k == 0)
			return 0;

		for(i = 0; i < b_month ; i++)
		{
			if(i == 1 || i == 3 || i == 5  || i == 7  || i == 8  || i == 10  || i == 12)
				b_sum += 31;
			if(i == 4 || i == 6 || i == 9  || i == 11)
				b_sum += 30;
			if(i == 2)
				b_sum += 28;
		}
		b_sum += b_day - 1;
		b_sum *= 24;
		b_sum += b_hour;
		b_sum *= 60;
		b_sum += b_min;

		for(i = 0; i < e_month ; i++)
		{
			if(i == 1 || i == 3 || i == 5  || i == 7  || i == 8  || i == 10  || i == 12)
				e_sum += 31;
			if(i == 4 || i == 6 || i == 9  || i == 11)
				e_sum += 30;
			if(i == 2)
				e_sum += 28;
		}
		e_sum += e_day - 1;
		e_sum *= 24;
		e_sum += e_hour;
		e_sum *= 60;
		e_sum += e_min;

		if(e_sum < b_sum)
			return 0;
	}

	void new_flight()   //新增航班
	{
		string flg;
		string b_place;
		string e_place;
		int b_month;
		int e_month;
		int b_data;
		int e_data;
		int b_hour;
		int e_hour;
		int b_min;
		int e_min;
		int price;
		string type;
		int sum;

		cout << "输入航班编号:";
		cin >> flg;
		
		cout << "输入出发地:";
		cin >> b_place;
		
		cout << "输入到达地:";
		cin >> e_place;

		
		cout << "输入出发时间:";
		cin >> b_month >> b_data >> b_hour >> b_min;

		cout << "输入到达时间:";
		cin >> e_month >> e_data >> e_hour >> e_min;

		int i = check_data(b_month, b_data, b_hour, b_min, e_month, e_data, e_hour, e_min);   //检查时间是否合法
		if(i == 0)
			cout << "输入信息有误!";

		else
		{
			cout << "输入票价:";
			cin >> price;
	
			cout << "输入飞机类型:";
			cin >> type;
	
			cout << "输入座位总数:";
			cin >> sum;
 
			F.push_back(new Flight(flg, b_place, e_place, b_month, b_data, b_hour, b_min, e_month, e_data, e_hour, e_min, price, type, sum, 0));
		}
	}

	void delete_flight(string flg)    //删除航班（管理员功能）
	{
		for(vector<Flight*>::iterator it = F.begin(); it != F.end(); it++)
		{
			if((*it)->getFlight().compare(flg) == 0)//找到这一航班，从vector中删除
			{
				F.erase(it);
				break;
			}
		}
	}

	void save_p()  //保存乘客信息
	{
		ofstream pFile("Passenger.txt");
		
		for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
		{
			pFile << "*" << endl;
			pFile << (*it)->getName() << endl;
			pFile << (*it)->getNum() << endl;
			pFile << (*it)->getNationality() << endl;
			pFile << (*it)->getTel() << endl;

			for(vector<string>::iterator its = (*it)->flight.begin(); its != (*it)->flight.end(); its++)
			{
				pFile << (*its) << endl;
			}
			pFile << "*";
			if(it != P.end() - 1)
				pFile << endl;
		}
	}

	void save_f()   //保存航班信息
	{
		ofstream fFile("Flight.txt");
		
		for(vector<Flight*>::iterator it = F.begin(); it != F.end(); it++)
		{
			
			fFile << (*it)->getFlight() << endl;
			fFile << (*it)->getB_place() << endl;
			fFile << (*it)->getE_place() << endl;
			fFile << (*it)->getB_month() << endl;
			fFile << (*it)->getB_data() << endl;
			fFile << (*it)->getB_hour() << endl;
			fFile << (*it)->getB_min() <<endl;
			fFile << (*it)->getE_month() << endl;
			fFile << (*it)->getE_data() << endl;
			fFile << (*it)->getE_hour() << endl;
			fFile << (*it)->getE_min() <<endl;
			fFile << (*it)->getPrice() <<endl;
			fFile << (*it)->getType() <<endl;
			fFile << (*it)->getSum() <<endl;
			fFile << (*it)->getN();
			if(it != F.end() - 1)
				fFile << endl;
		}
	}

	void noruser(string pass) //普通用户功能
	{
		int t;
		string fli;
		while(1)
		{
			cout << "请选择功能:" << endl;
			cout << "1.显示所有航班" << endl;
			cout << "2.查询航班" << endl;
			cout << "3.显示个人信息" << endl;
			cout << "4.预约航班" << endl;
			cout << "5.取消预约" << endl;
			cout << "6.退出" << endl;
			cin >> t;
			if(t == 1)
			{
				show_all_flight();
			}
			if(t == 2)
			{
				string fli;
				cout << "输入航班号:";
				cin >> fli;
				check_flight(fli);
			}
			if(t == 3)
			{
				show_one_passenger(pass);
			}
			if(t == 4)
			{
				cout << "输入航班号:";
				cin >> fli;
				book_flight(pass,fli);
				save_p();
				save_f();
			}
			if(t == 5)
			{
				cout << "输入航班号:";
				cin >> fli;
				remove_flight(pass,fli);
				save_p();
				save_f();
			}
			if(t == 6)
				break;
			cout << endl;
		}

	}

	void administrator()  //管理员功能
	{
		int t;
		string fli;
		while(1)
		{
			cout << "请选择功能:" << endl;
			cout << "1.显示所有航班" << endl;
			cout << "2.查询航班" << endl;
			cout << "3.显示个人信息" << endl;
			cout << "4.新增航班" << endl;
			cout << "5.删除航班" << endl;
			cout << "6.显示所有乘客信息" << endl;
			cout << "7.退出" << endl;
			cin >> t;
			if(t == 1)
			{
				show_all_flight();
			}
			if(t == 2)
			{
				string fli;
				cout << "输入航班号:";
				cin >> fli;
				check_flight(fli);
			}
			if(t == 3)
			{
				string pass;
				cout << "输入乘客护照:";
				cin >> pass;
				show_one_passenger(pass);
			}
			if(t == 4)
			{
				new_flight();
				save_f();
			}

			if(t == 5)
			{
				string flg;
				string pass;
				cout << "输入航班编号:";
				cin >> flg;
				delete_flight(flg);

				for(vector<Passenger*>::iterator it = P.begin(); it != P.end(); it++)
				{
					pass = (*it)->getNum();
					remove_flight(pass,fli);
				}
				save_f();
				save_p();
			}

			if(t == 6)
				show_all_passenger();
			
			if(t == 7)
				break;
			cout << endl;
		}

	}
};
/*int main()
{
	for(vector<Passenger*>::iterator it = user.P.begin(); it != user.P.end(); it++)
	{
		(*it)->showInfo();

		
		for(vector<string>::iterator its = (*it)->flight.begin(); its != (*it)->flight.end(); its++)
		{
			(*it)->showFlight((*its), user.F);
		}
	}

	for(vector<Flight*>::iterator fit = user.F.begin(); fit != user.F.end(); fit++)
	{
		(*fit)->showInfo();
	}
}
int main()
{
	int t;
	User user;
	cout << "choose user(1) or administrator(2)";
	cin >> t;

	if (t == 1)
		user.noruser("A123456");
	
	if (t == 2)
		user.administrator();
	return 0;
}
*/
int main()
{
	int t;
	User user;
	cout << "choose user(1) or administrator(2)";
	cin >> t;

	if (t == 1)
	{
		string ID;
		string password;
		string num;
		int k;

		cout << "1.注册" << endl;
		cout << "2.登陆" << endl;
		
		cin >> k;

		if(k == 1)
		{
			cout << "ID:";
			cin >> ID;
			cout << "password:";
			cin >> password;

			Passenger *p = signin(ID, password);
			user.P.push_back(p);
			user.save_p();
			user.noruser(p->getNum());
		}

		if(k == 2)
		{
			cout << "ID:";
			cin >> ID;
			cout << "password:";
			cin >> password;

			num = login(ID, password);
			user.noruser(num);
		}
	}
	if (t == 2)
	{
		string password;
		string num;
	
		cout << "password:";
		cin >> password;

		num = login("su", password);
		if(num.compare("--") == 0)
			user.administrator();
	}
    return 0;
}