#include "Rational.h"



Rational::Rational()
{
	setNumerator(0);
	setDenumerator(1);
}
Rational::Rational(int num, int denum)
{
	setNumerator(num);
	setDenumerator(denum);
}
Rational::~Rational()
{
}

void Rational::setNumerator(int num) { this->num = num; }
void Rational::setDenumerator(int denum) { this->denum = denum; }
int Rational::getNumerator() const { return num; }
int Rational::getDenumerator() const { return denum; }

const Rational& Rational::add(const Rational& other)
{
	this->num = num*other.denum + denum*other.num;
	this->denum = denum*other.denum;
	this->simplify();
	return *this;
}
const Rational& Rational::substract(const Rational& other)
{
	this->num = num*other.denum - other.num*denum;
	this->denum = denum*other.denum;
	this->simplify();
	return *this;
}
const Rational& Rational::multiply(const Rational& other)
{
	this->num = num*other.num;
	this->denum = denum*other.denum;
	this->simplify();
	return *this;
}
const Rational& Rational::divide(const Rational& other)
{
	this->num = num*other.denum;
	this->denum = denum*other.num;
	this->simplify();
	return *this;
}

Rational Rational::operator+(const Rational& other)
{
	Rational* rat = new Rational;
	rat->num = num*other.denum + denum*other.num;
	rat->denum = denum*other.denum;
	rat->simplify();
	return *rat;
}
Rational Rational::operator-(const Rational& other)
{
	Rational* rat = new Rational;
	rat->num = num*other.denum - other.num*denum;
	rat->denum = denum*other.denum;
	rat->simplify();
	return *rat;
}
Rational Rational::operator*(const Rational& other)
{
	Rational* rat = new Rational;
	rat->num = num*other.num;
	rat->denum = denum*other.denum;
	rat->simplify();
	return *rat;
}
Rational Rational::operator/(const Rational& other)
{
	Rational* rat = new Rational;
	rat->num = num*other.denum;
	rat->denum = denum*other.num;
	rat->simplify();
	return *rat;
}

const Rational& Rational::operator=(const Rational& other)
{
	if (this != &other)
	{
		this->num = other.num;
		this->denum = other.denum;
	}
	return *this;
}


ostream& operator<< (ostream& os, const Rational& rat)
{
	if (rat.num == 0)
		os << 0;
	else if(rat.denum == 1)
		os << rat.getNumerator();
	else
		os << rat.getNumerator() << '/' << rat.getDenumerator();
	return os;
}
istream& operator>> (istream& is, Rational& rat)
{
	is >> rat.num;
	is.ignore(1);
	is >> rat.denum;
	return is;
}

void Rational::simplify()
{
	for (int i = 2; i <= std::min(abs(num), abs(denum)); ++i)
		if (num%i == 0 && denum%i == 0)
		{
			num /= i;
			denum /= i;
			--i;
		}
}