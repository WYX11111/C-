#include <iostream>

using namespace std;

class Shape
{
public:
	virtual ostream& print(ostream& output) = 0;
	virtual ~Shape() {}
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
	~Triangle() {};
};

int main()
{
	Circle c(Point(1, 2, 3), 7);
	cout << c << '\n';

	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	cout << t << '\n';

	return 0;
}