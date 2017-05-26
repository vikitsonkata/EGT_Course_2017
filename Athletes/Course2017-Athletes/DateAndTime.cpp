#include "DateAndTime.h"

DateAndTime::DateAndTime()
{
	setDay(1);
	setMonth(1);
	setYear(1900);
}
DateAndTime::DateAndTime(int day, int month, int year,
	int hours, int minutes, int seconds)
{
	setDay(1);
	setMonth(1);
	setYear(1900);
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}
DateAndTime::~DateAndTime()
{
}

void DateAndTime::setDay(int day)
{
	this->day = day;
}
void DateAndTime::setMonth(int month)
{
	this->month = month;
}
void DateAndTime::setYear(int year)
{
	this->year = year;
}
void DateAndTime::setHours(int hours)
{
	this->hours = hours;
}
void DateAndTime::setMinutes(int minutes)
{
	this->minutes = minutes;
}
void DateAndTime::setSeconds(int seconds)
{
	this->seconds = seconds;
}

int DateAndTime::getDay() const
{
	return day;
}
int DateAndTime::getMonth() const
{
	return month;
}
int DateAndTime::getYear() const
{
	return year;
}
int DateAndTime::getHours() const
{
	return hours;
}
int DateAndTime::getMinutes() const
{
	return minutes;
}
int DateAndTime::getSeconds() const
{
	return seconds;
}

bool DateAndTime::operator> (const DateAndTime& other)
{
	if (year > other.year)
		return true;
	if (year < other.year)
		return false;
	if (month > other.month)
		return true;
	if (month < other.month)
		return false;
	if (day > other.day)
		return true;
	if (day < other.day)
		return false;
	if (hours > other.hours)
		return true;
	if (hours < other.hours)
		return false;
	if (minutes > other.minutes)
		return true;
	if (minutes < other.minutes)
		return false;
	if (seconds > other.seconds)
		return true;
	return false;
}
bool DateAndTime::operator>= (const DateAndTime& other)
{
	return (*this > other || *this == other);
}
bool DateAndTime::operator< (const DateAndTime& other)
{
	return (!(*this >= other));
}
bool DateAndTime::operator<= (const DateAndTime& other)
{
	return (!(*this>other));
}
bool DateAndTime::operator== (const DateAndTime& other)
{
	return (year == other.year && month == other.month &&
		day == other.day && hours == other.hours &&
		minutes == other.minutes && seconds == other.seconds);
}
bool DateAndTime::operator!= (const DateAndTime& other)
{
	return !(*this == other);
}

ostream& operator<< (ostream& os, const DateAndTime& other)
{
	os << "Date: " << other.day << '.' << other.month << '.' << other.year
		<< "Time: " << other.hours << ':' << other.minutes << ':' << other.seconds
		<< endl;
	return os;
}
istream& operator>> (istream& is, DateAndTime& other)
{
	cout << "Date: ";
	is >> other.day >> other.month >> other.year;
	cout << "Time: ";
	is >> other.hours >> other.minutes >> other.seconds;	
	return is;
}