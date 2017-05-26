#ifndef OLYMPICS
#define OLYMPICS
#include "E://c++ course2017/Course2017/athlets/StartInDiscipline.h"

class Olympics
{
public:
	Olympics();
	~Olympics();

	void addDiscipline(const StartInDiscipline&);
	
private:
	vector<StartInDiscipline> disciplines;
};

#endif