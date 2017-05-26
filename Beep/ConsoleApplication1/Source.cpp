#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
int main()
{
	string q;
	do {
		std::cin >> q;
		for(int i =0; i<q.length();i++)
		Beep(100 + (int)q[i]*15, 500);
	} while (q[0] != 'q');
	/*
	Beep(1200, 600);
	system("pause");*/
}