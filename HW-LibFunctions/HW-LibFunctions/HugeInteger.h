#ifndef _HUGEINTEGER_
#define _HUGEINTEGER_
//#include <vector>
//using std::vector;

const int SIZE = 40;

class HugeInteger
{
public:
	HugeInteger();
	~HugeInteger();
	//HugeInteger(vector<short>);

	void input();
	void output();

	bool isEqualTo(const HugeInteger&);
	bool isNotEqualTo(const HugeInteger&);
	bool isGreaterThan(const HugeInteger&);
	bool isLessThan(const HugeInteger&);
	bool isGreaterThanOrEqualTo(const HugeInteger&);
	bool isLessThanOrEqualTo(const HugeInteger&);
	bool isZero();

	HugeInteger add(const HugeInteger&);
	HugeInteger substract(const HugeInteger&);
	HugeInteger multiply(const HugeInteger&);
	HugeInteger divide(const HugeInteger&); // TO DO

	HugeInteger modulus() const;

private:
	char sign = '+';
	int number[SIZE];
	void simplifyF();
	void simplifyB();
	void reverseSign();
	int length() const;
	HugeInteger& divideBy10();
	HugeInteger& multiplyBy10();
};

#endif