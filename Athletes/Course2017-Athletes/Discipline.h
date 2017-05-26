#ifndef DISCIPLINE
#define DISCIPLINE
#include <string>
#include <iostream>
using namespace std;

class Discipline
{
	friend ostream& operator<< (ostream&, const Discipline&);
	friend istream& operator>> (istream&, Discipline&);

public:
	Discipline();
	Discipline(const string&);
	~Discipline();

	void setName(const string&);
	void setWorldRecord(const string&);
	void setCompetiotionRecord(const string&);

	const string& getName() const;
	const string& getWorldRecord() const;
	const string& getCompetitionRecord() const;
private:
	string name;
	static string worldRecord;
	static string competitionRecord ; 
};

#endif