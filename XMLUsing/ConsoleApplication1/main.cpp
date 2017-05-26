//============================================================================
// Name        : XMLTest.cpp
// Author      : Katya
// Version     :
// Copyright   : OnTarget
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "pugixml.hpp"
#include "Book.h"
#include "Operations.h"
using namespace std;

int main() {

	Operations op;
	op.traverse("Book.xml");
	

	//op.print();

	//cout << "The cheapest: " << endl;
	//op.cheapest().print();
	//cout << endl;
	//cout << "The Most Expenesive: " << endl;
	//op.theMostExpenesive().print();

	//op.printByPrice(30, "PrintByPrice30.txt");
	op.printByPrice(30);

	return 0;
}
