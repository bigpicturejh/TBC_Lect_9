#include <iostream>
#include<fstream>
using namespace std;


class Point
{
private:
	double _x, _y, _z;

public:
	Point(double x=0.0, double y=0.0, double z=0.0)
		:_x(x), _y(y), _z(z)
	{}

	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }

	//void print()
	//{
	//	cout << _x << " " << _y << " " << _z ;
	//}

	friend ostream& operator << (ostream& out, const Point& point)
	{
		out << point._x << " " << point._y << " " << point._z;

		return out;
	}

	friend istream& operator >> (istream& in,   Point& point)
	{
		in >> point._x >> point._y >> point._z;
		//out << point._x << " " << point._y << " " << point._z;

		return in;
	}
};

int main()
{
	ofstream of("out.txt");

	//Point p1(0.1, 0.2, 0.3), p2(1.4, 1.5, 3.4);
	Point p1, p2;

	cin >> p1 >> p2;
	/*p1.print();
	cout << " ";
	p2.print();
	cout << endl;*/

	cout << p1 << " " << p2 << endl;
	of << p1 << " " << p2 << endl;
	of.close();

	return 0;
}

