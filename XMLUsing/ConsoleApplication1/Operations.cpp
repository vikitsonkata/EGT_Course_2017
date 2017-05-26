/*
 * Operations.cpp
 *
 *  Created on: 23.05.2017 ã.
 *      Author: IVY
 */

#include "Operations.h"

Operations::Operations() {
	// TODO Auto-generated constructor stub

}

Operations::~Operations() {
	// TODO Auto-generated destructor stub
}

const vector<Book*>& Operations::getShelf() const {
	return shelf;
}

const Book& Operations::cheapest() const {
	if (!shelf.empty()) {
		double cheap = 100000;
		Book *g = shelf[0];
		for (unsigned int i = 0; i < shelf.size(); i++) {
			if (cheap > shelf[i]->getPrice()) {
				cheap = shelf[i]->getPrice();
				g = shelf[i];
			}
		}
		return *g;
	} else {
		cout << "Hey, you need to fill the vector." << endl;
	}
}

const Book& Operations::theMostExpenesive() const {
	if (!shelf.empty()) {
		double exp = 0.00;
		Book *g = shelf[0];
		for (unsigned int i = 0; i < shelf.size(); i++) {
			if (exp < shelf[i]->getPrice()) {
				exp = shelf[i]->getPrice();
				g = shelf[i];
			}
		}
		return *g;
	} else {
		cout << "Hey, you need to fill the vector." << endl;
	}
}

void Operations::setShelf(const vector<Book*>& shelf) {
	this->shelf = shelf;
}

void Operations::traverse(const char* name) {

	pugi::xml_document doc;
	if (!doc.load_file(name))
		cerr << "ERROR" << endl;

	pugi::xml_node books = doc.child("Bookstore");
	for (pugi::xml_node i = books.first_child(); i; i = i.next_sibling()) {
		Book *b = new Book;
		b->setTitle(i.child("title").text().as_string());
		b->setAuthor(i.child("author").text().as_string());
		b->setYear(i.child("year").text().as_int());
		b->setPrice(i.child("price").text().as_double());
		shelf.push_back(b);
	}

}

void Operations::print() {
	for (unsigned int i = 0; i < shelf.size(); i++) {
		shelf[i]->print();
		cout << endl;
	}
}

//bool Operations::printByPrice(const char* name, double price) const
//{
//	pugi::xml_document doc;
//	if (!doc.load_file(name))
//		cerr << "ERROR" << endl;
//
//	pugi::xml_node books = doc.child("Bookstore");
//	for(pugi::xml_node i = books.find_child(); i; i = i.next_sibling())
//		if (i.child("price").text().as_double() == price)
//		{
//			
//			
//			return true;
//		}
//	return false;
//}


bool Operations::printByPrice(double price , char* name) const
{
	bool done = false;
	for(unsigned int i = 0; i<shelf.size(); i++)
		if (shelf[i]->getPrice() == price)
		{
			if (name == "")
			{
			/*	string fileName = shelf[i]->getTitle();
				fileName.append(".txt");

				name = &fileName[0];*/
				name = "title.txt";
			}
			fstream outBook(name, ios::out | ios::app | ios::in);

			char title[30];
			outBook >> title;
			cout << title;

			if (!outBook)
				cerr << "File could not be opened." << endl;
			else
				cout << "!!!" << endl;

			if (done)
				outBook << endl;
			outBook << "Title: " << shelf[i]->getTitle() << endl
				<< "Author: " << shelf[i]->getAuthor() << endl
				<< "Year: " << shelf[i]->getYear() << endl
				<< "Price: " << shelf[i]->getPrice() << endl;
			done = true;
		}
	return done;
}
