#ifndef RATIONAL
#define RATIONAL
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int, int = 1);
	const Rational& operator=(const Rational&);
	~Rational();

	void setNumerator(int);
	void setDenumerator(int);
	int getNumerator() const;
	int getDenumerator() const;

	const Rational& add(const Rational&);
	const Rational& substract(const Rational&);
	const Rational& multiply(const Rational&);
	const Rational& divide(const Rational&);

	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);

	friend ostream& operator<< (ostream&, const Rational&);
	friend istream& operator>> (istream&, Rational&);
private:
	int num, denum;
	void simplify();
};

#endif