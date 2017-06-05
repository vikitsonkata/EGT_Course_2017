#include "HugeInteger.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::pow;

HugeInteger::HugeInteger()
{
	//cout << "def constructor" << endl;
	for (int i = 0; i < SIZE; ++i)
		this->number[i] = 0;
}
//HugeInteger::HugeInteger(vector<short>) {}
int HugeInteger::length() const
{
	//cout << "length" << endl;
	int i = 0;
	while (this->number[i] == 0)
		i++;
	return SIZE - i;
}
void HugeInteger::simplifyF()
{
	//cout << "simplifyF" << endl;
	int toNext = 0;
	for (int i = SIZE - 1; i >= 0; --i)
	{
		number[i] += toNext;
		toNext = number[i] / 10;
		number[i] %= 10;
	}
	if (toNext != 0)
		cout << "too big\n";
}
void HugeInteger::simplifyB()
{
	//cout << "simplifyB" << endl;
	int fromPrev = 0;
	bool revSign = false;
	for (int i = SIZE - 1; i > 0; --i)
		if (number[i] < 0)
		{
			if (number[i - 1] < 1)
			{
				number[i] *= (-1);
				revSign = true;
				continue;
			}
			number[i] += 10;
			number[i - 1]--;
		}
	if (revSign)
		reverseSign();
}
void HugeInteger::reverseSign()
{
	if (sign == '+')
		sign = '-';
	else
		sign = '+';
}
void HugeInteger::input()
{
	char s;
	int  digit, i = 0;
	cout << "Enter your number by digits:" << endl
		<< "Enter sign of the number ";
	cin >> s;
	if (s == '-' || s == '+')
		this->sign = s;
	else
		cout << "Invalid sign!" << endl
		<< "Sign is positive" << endl;
	do
	{
		//		cout << "Enter digit or enter \'.\'\t";
		cout << "Enter digit or enter \'(-1)'\t";
		cin >> digit;
		if (digit<0 || digit>9)
			continue;
		for (int j = i; j >= 0; --j)
			this->number[SIZE - 1 - j - 1] = this->number[SIZE - 1 - j];
		this->number[SIZE - 1] = digit;
		i++;
	} while (digit != -1 && i < SIZE);
	for (; i < SIZE; ++i)
		this->number[SIZE - 1 - i] = 0;
}
void HugeInteger::output()
{
	if (this->sign == '-')
		cout << this->sign;
	int i = 0;
	while (number[i] == 0)
		i++;
	if (i == SIZE)
		cout << '0';
	else
		for (; i < SIZE; ++i)
			cout << this->number[i];
	cout << endl;
}
HugeInteger HugeInteger::add(const HugeInteger & num)
{
	//cout << "add" << endl;
	HugeInteger res;
	if (sign == num.sign)
	{
		for (int i = 0; i < SIZE; ++i)
			res.number[i] = number[i] + num.number[i];
		res.simplifyF();
		res.sign = sign;
	}
	else if (sign == '-')
	{
		res = this->modulus().substract(num);
		res.reverseSign();
	}
	else
		res = this->substract(num.modulus());
	return res;
}
HugeInteger HugeInteger::substract(const HugeInteger& num)
{
	HugeInteger res;
	if (num.sign == '-')
	{
		res = this->add(num.modulus());
	}
	else if (sign == '-')
	{
		res = this->modulus().add(num);
		res.reverseSign();
	}
	else
	{

		for (int i = SIZE - 1; i >= 0; --i)
			res.number[i] = number[i] - num.number[i];
		res.simplifyB();

	}
	return res;
}
bool HugeInteger::isEqualTo(const HugeInteger& num)
{
	for (int i = SIZE - 1; i >= 0; --i)
		if (number[i] != num.number[i])
			return false;
	return true;
}
bool HugeInteger::isNotEqualTo(const HugeInteger& num)
{
	return isEqualTo(num) ? false : true;
}
bool HugeInteger::isGreaterThan(const HugeInteger& num)
{
	if (sign == num.sign)
	{
		if (length() > num.length())
			return true;
		for (int i = 0; i < SIZE; ++i)
		{
			if (number[i] == 0 && num.number[i] == 0)
				continue;
			if (number[i] <= num.number[i])
			{
				return false;
			}
		}
		return true;
	}
	else if (sign == '-')
		return false;
	else
		return true;
}
bool HugeInteger::isLessThan(const HugeInteger& num)
{
	if (sign == num.sign)
	{
		if (length() < num.length())
			return true;
		for (int i = 0; i < SIZE; ++i)
		{
			if (number[i] == 0 && num.number[i] == 0)
				continue;
			if (number[i] >= num.number[i])
				return false;
		}
		return true;
	}
	else if (sign == '+')
		return false;
	else
		return true;
}
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& num)
{
	return isEqualTo(num) || isGreaterThan(num) ? true : false;
}
bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& num)
{
	return isEqualTo(num) || isLessThan(num) ? true : false;
}
bool HugeInteger::isZero()
{
	for (int i = SIZE - 1; i >= 0; --i)
		if (number[i] != 0)
			return false;
	return true;
}
HugeInteger& HugeInteger::divideBy10()
{
	for (int i = SIZE - 1; i > 0; --i)
		number[i] = number[i - 1];
	return *this;
}
HugeInteger& HugeInteger::multiplyBy10()
{
	if (length() < SIZE)
		for (int i = 0; i < SIZE - 1; ++i)
			number[i] = number[i + 1];
	else
		cout << "too big" << endl;
	return *this;
}
HugeInteger HugeInteger::multiply(const HugeInteger& num) //?
{
	//cout << "multiply" << endl;
	HugeInteger res;
	if (sign != num.sign)
		res.reverseSign();
	int l1 = length(), l2 = num.length();
	for (int j = 0; j < l2; ++j)
		for (int i = 0; i < l1; ++i)
			if (SIZE - 1 - i - j < 0)
			{
				cout << "too big\n";
				return *this;
			}
			else
				res.number[SIZE - 1 - i - j] +=
				(number[SIZE - 1 - i] * num.number[SIZE - 1 - j]);
	res.simplifyF();
	return res;
}
HugeInteger HugeInteger::divide(const HugeInteger& num)
{
	HugeInteger res;
	if (isGreaterThanOrEqualTo(num))
	{
		int simplify = 0;
		HugeInteger copy = *this;
		while (copy.isGreaterThanOrEqualTo(num))
		{
			copy = copy.substract(num);
			res.number[SIZE - 1] ++;
			simplify++;
			if (simplify > 1000000)
				simplifyF();
		}
		simplifyF();
		if (sign != num.sign)
			res.sign = '-';
		return res;
		/*HugeInteger res, counter, temp;
		temp = *this;
		cout << "temp: ";
		temp.output();
		int len = length() - num.length() + 1;
		cout << "len = " << len << endl;
		counter.number[SIZE - len] = 1;
		cout << "counter: ";
		counter.output();
		for (int i = 0; i < len; ++i)
		{
		counter.multiply(num).output();
		HugeInteger multiplier = counter.multiply(num);

		while (temp.isGreaterThanOrEqualTo(multiplier)  )//&& !(counter.isZero()))
		{
		temp.output();
		counter.output();
		cout << endl;
		temp = temp.substract(multiplier);
		res = res.add(multiplier);
		}
		multiplier.divideBy10();
		}
		//res.number[SIZE - 1] --;
		return res;*/
	}
	else
		return *this;
}
HugeInteger HugeInteger::modulus() const
{
	HugeInteger res;
	for (int i = 0; i < SIZE; ++i)
		res.number[i] = number[i];
	return res;
}

HugeInteger::~HugeInteger()
{
}