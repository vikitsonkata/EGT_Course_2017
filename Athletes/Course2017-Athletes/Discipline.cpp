#include "Discipline.h"

string Discipline::worldRecord = " ";
string Discipline::competitionRecord = " ";

Discipline::Discipline()
{
}
Discipline::Discipline(const string& name)
{
	setName(name);
}
Discipline::~Discipline()
{
}

void Discipline::setName(const string& name)
{
	this->name = name;
}
void Discipline::setWorldRecord(const string& worlsdRecord)
{
		this->worldRecord = worldRecord;
}
void Discipline::setCompetiotionRecord(const string& competitionRecord)
{
		this->competitionRecord = competitionRecord;
}

const string& Discipline::getName() const
{
	return name;
}
const string& Discipline::getWorldRecord() const
{
	return worldRecord;
}
const string& Discipline::getCompetitionRecord() const
{
	return competitionRecord;
}

ostream& operator<< (ostream& os, const Discipline& other)
{
	os << other.name << endl
		<< "WR: " << other.worldRecord << endl
		<< "CR: " << other.competitionRecord << endl;
	return os;
}
istream& operator>> (istream& is, Discipline& other)
{
	is >> other.name >> other.worldRecord >> other.competitionRecord;
	return is;
}