#ifndef ATHLETE
#define ATHLETE
#include <iostream>
#include <string>
using namespace std;
//using std::string;

class Athlete
{
	friend ostream& operator<<(ostream&, const Athlete&);
	friend istream& operator>>(istream&, Athlete&);

public:
	Athlete();
	Athlete(const string&, const string&, const string&, const string&);
	~Athlete();

	void setFirstName(const string&);
	void setLastName(const string&);
	void setBest(const string&);
	void setNacionality(const string&);

	const string& getFirstName() const;
	const string& getLastName() const;
	const string& getBest() const;
	const string& getNacionality() const;

	bool operator== (const Athlete&) const;
	bool operator> (const Athlete&) const;
	bool operator< (const Athlete&) const;
	bool operator>= (const Athlete&) const;
	bool operator<= (const Athlete&) const;

	void print() const;
private:
	string firstName;
	string lastName;
	string best;
	string nacionality;
};

#endif