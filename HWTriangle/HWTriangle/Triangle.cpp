#include "Triangle.h"


istream& operator>> (istream& is, Triangle& other)
{
	is.ignore(1);
	is >> other.a;
	is.ignore(1);
	is >> other.b;
	is.ignore(1);
	is >> other.c;
	is.ignore(1);
	is >> other.h;
	return is;
}
ostream& operator<< (ostream& os, const Triangle& other)
{
	os << "=>" << other.a << "," << other.b << "," 
		<< other.c << "," << other.h << endl;
	return os;
}

Triangle::Triangle()
{
	a = b = c = h = 0;
}


Triangle::~Triangle()
{
}

void Triangle::setA(int a)
{
	this->a = a;
}
void Triangle::setB(int b)
{
	this->b = b;
}
void Triangle::setC(int c)
{
	this->c = c;
}
void Triangle::setH(int h)
{
	this->h = h;
}

int Triangle::getA() const
{
	return a;
}
int Triangle::getB() const
{
	return b;
}
int Triangle::getC() const
{
	return c;
}
int Triangle::getH() const
{
	return h;
}

bool Triangle::operator==(const Triangle& other)
{
	return (a == other.a && b == other.b &&
		c == other.c && h == other.h);
}
bool Triangle::operator!=(const Triangle& other)
{
	return !(*this == other);
}