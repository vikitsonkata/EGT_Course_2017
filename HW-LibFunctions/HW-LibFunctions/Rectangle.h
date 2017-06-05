#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
#include <iomanip>
using namespace std;

struct Point
{
	double x, y;
};

class Rectangle
{
	friend istream& operator>>(istream&, Rectangle&);
	friend ostream& operator<<(ostream&, const Rectangle&);
public:
	Rectangle();
	~Rectangle();

	Rectangle(double, double, double, double,
		double, double, double, double);
	Rectangle(Point, Point, Point, Point);

	void setPoint(int, double, double);
	void setPoint(int,  Point);

	bool isRectangle() const;
	bool isSquare() const;

	double width() const;
	double length() const;
	double perimeter() const;
	double area() const;

	Point downLeftCorner() const;
	Point downRightCorner() const;
	Point upLeftCorner() const;
	Point upRightCorner() const;
	Point* center() const;

	void show(char = '#', char = '*', int = 0, int = 0) const; //TO DO

private:
	Point points[2][2];
	void verify(Point&);
	bool isPerpendicular(Point&, Point&) const;
};

#endif