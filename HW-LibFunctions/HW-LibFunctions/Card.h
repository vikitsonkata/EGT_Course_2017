#ifndef CARD
#define CARD
#include <iostream>
using namespace std;

enum SUIT {CLUBS, DIAMONDS, HEARTS, SPADES};

class Card
{
public:
	Card();
	~Card();

	Card(int, SUIT = HEARTS);
	
	void setNumber(int);
	void setSuit(SUIT);

	int getNumber() const;
	SUIT getSuit() const;

	void print() const;

	bool operator== (const Card&);
	bool operator< (const Card&);
	bool operator<= (const Card&);
	bool operator> (const Card&);
	bool operator>= (const Card&);
	bool operator!= (const Card&);
private:
	int number;
	SUIT suit;
};

#endif