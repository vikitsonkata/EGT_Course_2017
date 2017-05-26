/*
 * Book.h
 *
 *  Created on: 23.05.2017 ã.
 *      Author: IVY
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
#include "pugixml.hpp"
using namespace std;

class Book {

private:
	string title;
	string author;
	int year;
	double price;
public:
	Book();
	virtual ~Book();

	// setters & getters
	const string& getAuthor() const;
	void setAuthor(const string& author);

	double getPrice() const;
	void setPrice(double price);

	const string& getTitle() const;
	void setTitle(const string& title);

	int getYear() const;
	void setYear(int year);

	// method
	void print() const;

};

#endif /* BOOK_H_ */
