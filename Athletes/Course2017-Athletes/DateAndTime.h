#ifndef DATE
#define DATE
#include <iostream>
using namespace std;

class DateAndTime
{
public:
	DateAndTime();
	DateAndTime(int, int, int, int, int, int);
	~DateAndTime();

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setHours(int);
	void setMinutes(int);
	void setSeconds(int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	bool operator> (const DateAndTime&);
	bool operator>= (const DateAndTime&);
	bool operator< (const DateAndTime&);
	bool operator<= (const DateAndTime&);
	bool operator== (const DateAndTime&);
	bool operator!= (const DateAndTime&);

	friend ostream& operator<< (ostream&, const DateAndTime&);
	friend istream& operator>> (istream&, DateAndTime&);
private:
	int day, month, year;
	int hours, minutes, seconds;
};

#endif