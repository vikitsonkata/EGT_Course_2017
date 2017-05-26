#include "StartInDiscipline.h"
#include <algorithm>

StartInDiscipline::StartInDiscipline()
{
	type = qualifation;
}
StartInDiscipline::StartInDiscipline(const DateAndTime& time,
	const Discipline& discipline)
{
	setDateAndTime(time);
	setDiscipline(discipline);
	setType();
}
StartInDiscipline::~StartInDiscipline()
{
}

void StartInDiscipline::setDateAndTime(const DateAndTime& time)
{
	this->time = time;
}
void StartInDiscipline::setDiscipline(const Discipline& discipline)
{
	this->discipline = discipline;
}
void StartInDiscipline::setAthletes(const vector<Athlete>& athletes)
{
	this->athletes = athletes;
}
void StartInDiscipline::setType()
{
	int temp;
	cout << "Level in competition: \n"
		<< "\t0 - final\n\t1 - semifinal\n"
		<< "\t2 - quarterfinal\n\t3 - qualification\n";
	cin >> temp;
	switch (temp)
	{
	case 0: type = final; break;
	case 1: type = semifinal; break;
	case 2: type = quarterfinal; break;
	default: type = qualifation;
	}
}

const DateAndTime& StartInDiscipline::getDateAndTime() const
{
	return time;
}
const Discipline& StartInDiscipline::getDiscipline() const
{
	return discipline;
}
const vector<Athlete> StartInDiscipline::getAthletes() const
{
	return athletes;
}

void StartInDiscipline::showLevelInCompetition() const
{
	switch (type)
	{
	case 0: cout << "final" << endl; break;
	case 1: cout << "semifinal" << endl; break;
	case 2: cout << "quarterfinal" << endl; break;
	case 3: cout << "qualifation" << endl; break;
	default: cout << "no level known in the competition" << endl;
	};
}
void StartInDiscipline::addAthlete(const Athlete& athlete)
{
	athletes.push_back(athlete);
	if (discipline.getCompetitionRecord() == " " 
		|| discipline.getCompetitionRecord() > athlete.getBest())
		discipline.setCompetiotionRecord(athlete.getBest());
	if (discipline.getWorldRecord() == " "
		|| discipline.getWorldRecord() > athlete.getBest())
		discipline.setWorldRecord(athlete.getBest());
}
//bool pred(Athlete& q, Athlete& w)
//{
//	return q > w;
//}
void StartInDiscipline::sort()
{
	std::sort(athletes.begin(), athletes.end());
}


bool StartInDiscipline::find(vector<int>& vec, int toFind) const
{
	for (unsigned int i = 0; i < vec.size() - 1; ++i)
		if (vec[i] == toFind)
			return true;
	return false;
}
bool StartInDiscipline::find(vector<Athlete>& vec, const Athlete& toFind) const
{
	for (unsigned int i = 0; i < vec.size() - 1; ++i)
		if (vec[i] == toFind)
			return true;
	return false;
}

const vector<Athlete>& StartInDiscipline::toNextRound() const
{
	vector<Athlete>* res = new vector<Athlete>;
	int size = athletes.size() / 4;
	size = size ? size : 1;
	for (int i = 0; i < size; ++i)
		res->push_back(athletes[i]);
	return *res;
}
const vector<Athlete>& StartInDiscipline::bestAthletes() const
{
	vector<Athlete> someAthletes;
	vector<int> indexes;
	for (int i = 1;	(i < athletes.size() - 1) && !(find(indexes,i)); ++i)
	{
		int max = 0;
		if (athletes[i] > athletes[max])
		/*if ((athletes[i].getBest()[athletes[i].getBest().length() - 1] == 'm' &&
			athletes[i].getBest() > athletes[max].getBest()) ||
			(athletes[i].getBest()[athletes[i].getBest().length() - 1] == 's'
				&& athletes[i].getBest() < athletes[max].getBest()))*/
			max = i;
		indexes.push_back(max);
		someAthletes.push_back(athletes[max]);
	}
	return someAthletes;
}

ostream& operator<< (ostream& os, const StartInDiscipline& other)
{
	os << other.time << other.discipline;
	for (unsigned int i = 0; i < other.athletes.size(); ++i)
		os << other.athletes[i];
	other.showLevelInCompetition();
	return os;
}
istream& operator>> (istream& is, StartInDiscipline& other)
{
	is >> other.time >> other.discipline;
	other.setType();	
	return is;
}
