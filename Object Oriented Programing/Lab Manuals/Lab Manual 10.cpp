#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int c1, int c2)
	{
		x = c1;
		y = c2;
		cout << "Point() called" << endl;
	}
	void print()
	{
		cout << "( " << x << " , " << y << " )" << endl;
	}
	~Point()
	{
		cout << "~Point() called" << endl;
	}
};
class Circle
{
	Point center;
	float radius;
public:
	Circle(int c1, int c2, int r): center(c1,c2)
	{
		radius = r;
		cout << "Circle() called" << endl;
	}
	void print()
	{
		cout << "The center of the circle is at";
		center.print();
		cout << " The radius of the circle is: " << radius << endl;
	}
	~Circle()
	{
		cout << "~Circle() called" << endl;
	}
};
void main()
{
	Circle c(3, 4, 2.5);
	c.print();
}