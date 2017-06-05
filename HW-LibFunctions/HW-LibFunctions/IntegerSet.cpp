#include "IntegerSet.h"



ostream& operator<< (ostream& os, const IntegerSet& rhs)
{
	for (int i = 0; i < SIZE_SET; i++)
		if (rhs.integers[i])
			os << i << ' ';
	return os;
}
istream& operator>> (istream&  is, IntegerSet& rhs)
{
	int i = 0;
	while (i>=0 && i<SIZE_SET)
	{
		is >> i;
		rhs.integers[i] = true;
	}
	return is;
}

IntegerSet::IntegerSet()
{
	for (int i = 0; i < SIZE_SET; i++)
		integers[i] = false;
}


IntegerSet::~IntegerSet()
{
}

IntegerSet::IntegerSet(int* arr, int SIZE_SET)
{
	for (int i = 0; i < SIZE_SET; i++)
		integers[arr[i]] = true;
}

void IntegerSet::insertElement(int elm)
{
	integers[elm] = true;
}
void IntegerSet::deleteElement(int elm)
{
	integers[elm] = false;
}
void IntegerSet::print()
{
	for (int i = 0; i < SIZE_SET; i++)
		if (integers[i])
			cout << i << ' ';
	cout<<endl;
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& rhs)
{
	IntegerSet toReturn;
	for (int i = 0; i < SIZE_SET; i++)
		if (integers[i] || rhs.integers[i])
			toReturn.integers[i] = true;
	return toReturn;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& rhs)
{
	IntegerSet toReturn;
	for (int i = 0; i < SIZE_SET; i++)
		if (integers[i] && rhs.integers[i])
			toReturn.integers[i] = true;
	return toReturn;
}

bool IntegerSet::isEqualTo(const IntegerSet& rhs)
{
	for (int i = 0; i < SIZE_SET; i++)
		if (!(integers[i] == rhs.integers[i]))
			return false;
	return true;
}
