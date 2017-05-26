/*
 * Book.cpp
 *
 *  Created on: 23.05.2017 ã.
 *      Author: IVY
 */

#include "Book.h"

Book::Book() {
	// TODO Auto-generated constructor stub
}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

// setters & getters
const string& Book::getAuthor() const {
	return author;
}

void Book::setAuthor(const string& author) {
	this->author = author;
}

double Book::getPrice() const {
	return price;
}

void Book::setPrice(double price) {
	this->price = price;
}

const string& Book::getTitle() const {
	return title;
}

void Book::setTitle(const string& title) {
	this->title = title;
}

int Book::getYear() const {
	return year;
}

void Book::setYear(int year) {
	this->year = year;
}

void Book::print() const {
	cout << "Title: " << getTitle() << endl
			<< "Author: " << getAuthor() << endl
			<< "Year: " << getYear() << endl
			<< "Price: " << getPrice() << endl;
}
