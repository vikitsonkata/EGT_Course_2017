#ifndef CARDS
#define CARDS
#include "Card.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cerr;
using std::endl;

enum GAME {BLACKJACK, POKER};

class Cards
{
public:
	Cards();
	~Cards();

	Cards(const vector<Card>&);

	void setCards(const vector<Card>&);
	void setGAME(GAME);

	const vector<Card>& getCards() const;
	GAME getGAME() const;

	void addCard(const Card&);
	void print() const;

	bool operator==(const Cards&) const;
	bool operator!=(const Cards&) const;
	bool operator<=(const Cards&) const;
	bool operator>=(const Cards&) const;
	bool operator<(const Cards&) const;
	bool operator>(const Cards&) const;

private:
	vector<Card> cards;
	GAME game;
};

#endif