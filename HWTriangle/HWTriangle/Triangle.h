#ifndef TRIANGLE
#define TRIANGLE
#include <iostream>
using namespace std;

class Triangle
{
	friend istream& operator>> (istream&, Triangle&);
	friend ostream& operator<< (ostream&, const Triangle&);
public:
	Triangle();
	~Triangle();

	void setA(int);
	void setB(int);
	void setC(int);
	void setH(int);

	int getA() const;
	int getB() const;
	int getC() const;
	int getH() const;

	bool operator==(const Triangle&);
	bool operator!=(const Triangle&);
private:
	int a, b, c, h;
};

#endif