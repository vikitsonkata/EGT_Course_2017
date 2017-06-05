#include "ComplexNumber.h"



ComplexNumber::ComplexNumber()
{
	setReal(0);
	setImaginary(0);
}

ComplexNumber::~ComplexNumber()
{
}


ostream& operator<<(ostream& os, const ComplexNumber& rhs)
{
	if (rhs.real != 0)
		os << rhs.real;
	if (rhs.imaginary != 0)
	{
		if (rhs.imaginary > 0)
			os << '+';
		os << rhs.imaginary << "*i";
	}
	return os;
}
istream& operator>>(istream& is, ComplexNumber& rhs)
{
	is >> rhs.real;
	is.ignore(1);
	is >> rhs.imaginary;
	is.ignore(2);
	//cout << "Enter real part: ";
	//is >> rhs.real;
	//cout << "Enter imaginary part: ";
	//is >> rhs.imaginary;
	return is;
}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
	setReal(real);
	setImaginary(imaginary);
}

void ComplexNumber::setReal(double real)
{
	this->real = real;
}
void ComplexNumber::setImaginary(double imaginary)
{
	this->imaginary = imaginary;
}

double ComplexNumber::getReal() const
{
	return real;
}
double ComplexNumber::getImaginary() const
{
	return imaginary;
}

bool ComplexNumber::operator==(const ComplexNumber& rhs) const
{
	return (real == rhs.real && imaginary == rhs.imaginary);
}
bool ComplexNumber::operator!=(const ComplexNumber& rhs) const
{
	return (*this != rhs);
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) const
{
	ComplexNumber res;
	res.setReal(real + rhs.real);
	res.setImaginary(imaginary + rhs.imaginary);
	return res;
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs) const
{
	ComplexNumber res;
	res.setReal(real - rhs.real);
	res.setImaginary(imaginary - rhs.imaginary);
	return res;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhs) const
{
	ComplexNumber res;
	res.setReal((real * rhs.real) - (imaginary * rhs.imaginary));
	res.setImaginary((imaginary * rhs.real) + (real * rhs.imaginary));
	return res;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& rhs) const
{
	ComplexNumber res;
	ComplexNumber num((*this) * ~rhs);
	double denum((rhs*(~rhs)).getReal());
	res.setReal(num.real/denum);
	res.setImaginary(num.imaginary/denum);
	return res;
}
ComplexNumber ComplexNumber::operator!() const
{
	ComplexNumber res(-real, -imaginary);
	return res;
}
ComplexNumber ComplexNumber::operator~() const
{
	ComplexNumber res(real, -imaginary);
	return res;
}

double ComplexNumber::modulus() const
{
	return sqrt(real*real+imaginary*imaginary);
}

bool ComplexNumber::isReal() const
{
	return imaginary == 0;
}
bool ComplexNumber::isImaginary() const
{
	return real == 0;
}