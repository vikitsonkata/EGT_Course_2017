#include "Athlete.h"
#include <iostream>
#include <ostream>
using namespace std;

ostream& operator<< (ostream& os, const Athlete& other)
{
	os << other.getFirstName() << " " << other.getLastName() << endl
		<< other.getBest() << " " << other.getNacionality() << endl;
	return os;
}
istream& operator>> (istream& is, Athlete& other)
{
	is >> other.firstName >> other.lastName 
		>> other.best >> other.nacionality;
	return is;
}

Athlete::Athlete()
{
}
Athlete::Athlete(const string& firstName, const string& lastName,
	const string& best, const string& nacionality)
{
	setFirstName(firstName);
	setLastName(lastName);
	setBest(best);
	setNacionality(nacionality);
}
Athlete::~Athlete()
{
}

void Athlete::setFirstName(const string& firstName) 
{
	this->firstName = firstName; 
}
void Athlete::setLastName(const string& lastName)
{
	this->lastName = lastName; 
}
void Athlete::setBest(const string& best) 
{
	this->best = best; 
}
void Athlete::setNacionality(const string& nacionality) 
{
	this->nacionality = nacionality; 
}

const string& Athlete::getFirstName() const 
{
	return firstName; 
}
const string& Athlete::getLastName() const 
{
	return lastName; 
}
const string& Athlete::getBest() const 
{
	return best; 
}
const string& Athlete::getNacionality() const 
{
	return nacionality; 
}

bool Athlete::operator== (const Athlete& other) const
{
	if (best==other.best)
		return true;
	return false;
}
bool Athlete::operator> (const Athlete& other) const
{
	if (best[best.length() - 1] != other.best[other.best.length() - 1])
		cout << "Different type of athletes!";
	if((best[best.length()-1] == 'm' && best > other.best)
		|| (best[best.length() - 1] == 's' && best<other.best))
			return true;		
	return false;
}
bool Athlete::operator< (const Athlete& other) const
{
	if (*this == other || *this > other)
		return false;
	return true;
}
bool Athlete::operator>= (const Athlete& other) const
{
	return *this > other || *this == other;
}
bool Athlete::operator<= (const Athlete& other) const
{
	return *this < other || *this == other;
}

void Athlete::print() const
{
	cout << *this;
}