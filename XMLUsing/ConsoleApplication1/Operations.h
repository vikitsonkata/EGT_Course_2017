/*
 * Operations.h
 *
 *  Created on: 23.05.2017 ã.
 *      Author: IVY
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "pugixml.hpp"
#include "Book.h"
using namespace std;

class Operations {
private:
	vector<Book*> shelf;
public:
	Operations();
	virtual ~Operations();

	// methods
	void traverse(const char*);
	void print();
	const Book& cheapest() const;
	const Book& theMostExpenesive() const;
	bool printByPrice(double, char* = "") const;

	// setters & getters
	const vector<Book*>& getShelf() const;
	void setShelf(const vector<Book*>& shelf);
};

#endif /* OPERATIONS_H_ */
