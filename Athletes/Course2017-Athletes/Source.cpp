#include <iostream>
#include "Athlete.h"
#include "Discipline.h"
#include "StartInDiscipline.h"
using namespace std;

int main()
{
	Athlete asd, qwe;
	Discipline dis;
	dis.setName("run 200m");
	dis.setWorldRecord("10.0s");
	//dis.setWorldRecord("10.0s");
	asd.setBest("12.4s");
	qwe.setBest("11.3s");
	cout << asd.getBest() << " < " << 
		qwe.getBest() << " ? is " <<
		boolalpha << (asd > qwe) << endl;
	StartInDiscipline o;
	o.setDiscipline(dis);
	o.setType();
	o.setDateAndTime(*(new DateAndTime(1, 2, 3, 4, 5, 6)));
	o.addAthlete(asd);
	o.addAthlete(qwe);
	o.addAthlete(asd);
	cout << o;
	o.sort();
	cout << o;
}