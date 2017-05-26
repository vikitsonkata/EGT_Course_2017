#include "Olympics.h"



Olympics::Olympics()
{
}


Olympics::~Olympics()
{
}

void Olympics::addDiscipline(const StartInDiscipline& discipline)
{
	disciplines.push_back(discipline);
}