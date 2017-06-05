#ifndef COMPLEXNUMBER
#define COMPLEXNUMBER
#include <iostream>
using namespace std;

class ComplexNumber
{
	friend ostream& operator<<(ostream&, const ComplexNumber&);
	friend istream& operator>>(istream&, ComplexNumber&);
public:
	ComplexNumber();
	~ComplexNumber();

	ComplexNumber(double, double = 0);

	void setReal(double);
	void setImaginary(double);

	double getReal() const;
	double getImaginary() const;

	bool operator==(const ComplexNumber&) const;
	bool operator!=(const ComplexNumber&) const;
	ComplexNumber operator+(const ComplexNumber&) const;
	ComplexNumber operator-(const ComplexNumber&) const;
	ComplexNumber operator*(const ComplexNumber&) const;
	ComplexNumber operator/(const ComplexNumber&) const;
	ComplexNumber operator~() const;
	ComplexNumber operator!() const;

	double modulus() const;

	bool isReal() const;
	bool isImaginary() const;
private:
	double real;
	double imaginary;
};

#endif