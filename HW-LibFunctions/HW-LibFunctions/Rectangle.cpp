#include "Rectangle.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, Rectangle& rhs)
{
	is >> rhs.points[0][0].x
		>> rhs.points[0][0].y

		>> rhs.points[0][1].x
		>> rhs.points[0][1].y

		>> rhs.points[1][0].x
		>> rhs.points[1][0].y

		>> rhs.points[1][1].x
		>> rhs.points[1][1].y;
	return is;
}
ostream& operator<<(ostream& os, const Rectangle& rhs)
{
	os << rhs.points[1][1].x << "," << rhs.points[1][1].y << "\t"
		<< rhs.points[1][0].x << "," << rhs.points[1][0].y << "\n"
		<< rhs.points[0][0].x << "," << rhs.points[0][0].y << "\t"
		<< rhs.points[0][1].x << "," << rhs.points[0][1].y;
	return os;
}

Rectangle::Rectangle()
{
	setPoint(0, 0, 0);
	setPoint(1, 0, 0);
	setPoint(2, 0, 0);
	setPoint(3, 0, 0);
}


Rectangle::~Rectangle()
{
}


Rectangle::Rectangle(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
	setPoint(3, x4, y4);
	if (!isRectangle())
		std::cout << "Not a rectangle!" << std::endl;
}

Rectangle::Rectangle(Point point1, Point point2, Point point3, Point point4)
{
	setPoint(0, point1);
	setPoint(1, point2);
	setPoint(2, point3);
	setPoint(3, point4);
	if(!isRectangle())
		std::cout << "Not a rectangle!" << std::endl;
}

void Rectangle::setPoint(int i, double x, double y)
{
	points[i / 2][i % 2].x = x;
	points[i / 2][i % 2].y = y;
	verify(points[i / 2][i % 2]);
}
void Rectangle::setPoint(int i, Point point)
{
	points[i / 2][i % 2].x = point.x;
	points[i / 2][i % 2].y = point.y;
	verify(points[i / 2][i % 2]);
}

bool Rectangle::isRectangle() const 
{
	Point v1, v2, v3, v4;
	v1.x = points[0][0].x - points[0][1].x;
	v1.y = points[0][0].y - points[0][1].y;

	v2.x = points[0][1].x - points[1][0].x;
	v2.y = points[0][1].y - points[1][0].y;

	v3.x = points[1][0].x - points[1][1].x;
	v3.y = points[1][0].y - points[1][1].y;

	v4.x = points[1][1].x - points[0][0].x;
	v4.y = points[1][1].y - points[0][0].y;

	return isPerpendicular(v1, v2) &&
		isPerpendicular(v2, v3) &&
		isPerpendicular(v3, v4);
}
bool Rectangle::isSquare() const
{
	return width() == length();
}

double Rectangle::perimeter() const
{
	return 2*(width()+length());
}
double Rectangle::area() const
{
	return width()*length();
}

double Rectangle::width() const
{
	double side1, side2;
	side1 = sqrt((points[0][0].x - points[0][1].x)*(points[0][0].x - points[0][1].x) +
		(points[0][0].y - points[0][1].y)*(points[0][0].y - points[0][1].y));
	side2 = sqrt((points[0][0].x - points[1][1].x)*(points[0][0].x - points[1][1].x) +
		(points[0][0].y - points[1][1].y)*(points[0][0].y - points[1][1].y));
	return side1 < side2 ? side1 : side2;
}
double Rectangle::length() const
{
	double side1, side2;
	side1 = sqrt((points[0][0].x - points[0][1].x)*(points[0][0].x - points[0][1].x) +
		(points[0][0].y - points[0][1].y)*(points[0][0].y - points[0][1].y));
	side2 = sqrt((points[0][0].x - points[1][1].x)*(points[0][0].x - points[1][1].x) +
		(points[0][0].y - points[1][1].y)*(points[0][0].y - points[1][1].y));
	return side1 > side2 ? side1 : side2;
}

void Rectangle::verify(Point& point)
{
	if (point.x < 0)
		point.x = 0;
	if (point.x > 20)
		point.x = 20;
	if (point.y < 0)
		point.y = 0;
	if (point.y > 20)
		point.y = 20;
}

bool Rectangle::isPerpendicular(Point& vec1, Point& vec2) const
{
	return (vec1.x*vec2.x + vec1.y*vec2.y == 0);
}

Point Rectangle::downLeftCorner() const
{
	return points[0][0];
}
Point Rectangle::downRightCorner() const
{
	return points[0][1];
}
Point Rectangle::upLeftCorner() const
{
	return points[1][1];
}
Point Rectangle::upRightCorner() const
{
	return points[1][0];
}
Point* Rectangle::center() const
{
	Point* point = new Point;
	point->x = 0;
	point->y = 0;
	for (int i = 0; i < 4; i++)
	{
		point->x += points[i / 2][i % 2].x;
		point->y += points[i / 2][i % 2].y;
	}
	point->x /= 4;
	point->y /= 4;	
	return point;
}


void Rectangle::show(char fillCharacter, char perimeterCharacter,
	int translateX, int translateY) const
{
	bool drawX = false, drawY = false;
	cout << '/' << setw(25) << setfill('-') << '\\' << endl;
	for (int j = 24; j >= 0 ; j--)
	{
		cout << '|';
		for (int i = 0; i < 25; i++)
		{
			if ((i == upLeftCorner().x && j == upLeftCorner().y)
				|| (i == upRightCorner().x && j == upRightCorner().y)
				|| (i == downLeftCorner().x && j == downLeftCorner().y)
				|| (i == downRightCorner().x && j == downRightCorner().y))
				cout << '^';
			else
				if (((i - translateX <= upRightCorner().x && i - translateX >= upLeftCorner().x) &&
					(j - translateY <= upRightCorner().y && j - translateY >= upLeftCorner().y))
					|| ((i - translateX <= downRightCorner().x && i - translateX >= downLeftCorner().x) &&
					(j - translateY <= downRightCorner().y && j - translateY >= downLeftCorner().y))
					|| ((i - translateX <= upRightCorner().x && i - translateX >= downRightCorner().x) &&
					(j - translateY <= upRightCorner().y && j - translateY >= downRightCorner().y))
					|| ((i - translateX <= upLeftCorner().x && i - translateX >= downLeftCorner().x) &&
					(j - translateY <= upLeftCorner().y && j - translateY >= downLeftCorner().y)))
					//|| (i == (int)((downRightCorner().x + downLeftCorner().x) / 2) &&
					//	j == (int)((downRightCorner().y + downLeftCorner().y) / 2))
					//|| (i == (int)((upRightCorner().x + downRightCorner().x) / 2) &&
					//	j == (int)((upRightCorner().y + downRightCorner().y) / 2))
					//|| (i == (int)((upLeftCorner().x + downLeftCorner().x) / 2) &&
					//	j == (int)((upLeftCorner().y + downLeftCorner().y) / 2)))
					//cout << i << j;
					cout << perimeterCharacter;
				else
					cout << ' ';
		}
		cout << '|' << endl;
	}
	cout << '\\' << setw(25) << setfill('-') << '/' << endl;
}