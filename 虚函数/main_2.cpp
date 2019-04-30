#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual ostream& print(ostream& output) = 0;
	virtual ~Shape() {}
	virtual double getR() = 0;
};

class Point
{
private:
	int m_x;
	int m_y;
	int m_z;

public:
	Point ()
	{
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	Point (int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{
	
	}

	friend ostream& operator << (ostream& out, Point& p) 
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Circle : public Shape
{
private:
	Point a;
	double r;
public:
	Circle(Point A, double R)
	{
		a = A;
		r = R;
	}

	virtual ostream& print(ostream& output)
	{
		output << "Circle(" << a << ", " << r << ")";
		return output;
	}
	friend ostream& operator << (ostream& output, Circle c)
	{
		output << "Circle(" << c.a << ", " << c.r << ")";
		return output;
	}
	double getR()
	{
		return r;
	}
	~Circle() {};
};

class Triangle : public Shape
{
private:
	Point a;
	Point b;
	Point c;
public:
	Triangle(Point A, Point B, Point C)
	{
		a = A;
		b = B;
		c = C;
	}

	virtual ostream& print(ostream& output)
	{
		output << "Triangle(" << a << ", " << b << ", " << c << ")";
		return output;
	}

	friend ostream& operator << (ostream& output, Triangle t)
	{
		output << "Triangle(" << t.a << ", " << t.b << ", " << t.c << ")";
		return output;
	}
	double getR()
	{
		return 0;
	}
	~Triangle() {};
};

ostream& getLargestRadius(ostream& output, vector<Shape*> v)
{
	double max = 0;
	int max_foot = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if(v[i]->getR() > max)
		{
			max = v[i]->getR();
			max_foot = i;
		}
	}
	v[max_foot]->print(output);
	output << '\n' << v[max_foot]->getR();
	return output;
}

/*
double getLargestRadius(vector<Shape*> v)
{
	double max = 0;
	int max_foot = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if(v[i]->getR() > max)
		{
			max = v[i]->getR();
			max_foot = i;
		}
	}
	v[max_foot]->print(cout);
	cout << '\n';
	return max;
}
*/
int main()
{
	vector<Shape*> v;
	v.push_back(new Circle(Point(1,2,3),7));
	v.push_back(new Triangle(Point(1,2,3),Point(4,5,6),Point(7,8,9)));
	v.push_back(new Circle(Point(4,5,6),3));

	cout << "The largest radius is:";
	getLargestRadius(cout,v) << '\n';
	return 0;
}