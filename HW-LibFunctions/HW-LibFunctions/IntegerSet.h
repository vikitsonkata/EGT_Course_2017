#ifndef INTEGERSET
#define INTEGERSET
#include <iostream>
using namespace std;

const int SIZE_SET = 100;

class IntegerSet
{
	friend ostream& operator<< (ostream&, const IntegerSet&);
	friend istream& operator>> (istream&, IntegerSet&); // TO DO
public:
	IntegerSet();
	~IntegerSet();

	IntegerSet(int*, int);

	void insertElement(int);
	void deleteElement(int);
	void print();

	IntegerSet unionOfSets(const IntegerSet&);
	IntegerSet intersectionOfSets(const IntegerSet&);

	bool isEqualTo(const IntegerSet&);
private:
	bool integers[SIZE_SET];
};

#endif