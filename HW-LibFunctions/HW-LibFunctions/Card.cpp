#include "Card.h"

Card::Card()

{
	setNumber(1);
	setSuit(SPADES);
}

Card::~Card()
{
}

Card::Card(int number, SUIT suit)
{
	setNumber(number);
	setSuit(suit);
}

void Card::setNumber(int number)
{
	if (number < 1 || number>13)
		this->number = 1;
	else
		this->number = number;
}
void Card::setSuit(SUIT suit)
{
	this->suit = suit;
}

int Card::getNumber() const
{
	return number;
}
SUIT Card::getSuit() const
{
	return suit;
}

void Card::print() const
{
	if(number>2&&number<=10)
		cout << number;
	else switch (number)
	{
	case 1: cout << "Ace"; break;
	case 11: cout << "Jack"; break;
	case 12: cout << "Queen"; break;
	case 13: cout << "Kig"; break;
	default:
		cerr << "Not a card" << endl;
	}
	switch (suit)
	{
	case SPADES: cout << " of spades"; break;
	case DIAMONDS: cout << " of diamonds"; break;
	case HEARTS: cout << " of hearts"; break;
	case CLUBS: cout << " of clubs"; break;
	default:
		cerr << "Not a card" << endl;
	}
	cout << endl;
}

bool Card::operator== (const Card& other)
{
	return number == other.number && suit == other.suit;
}
bool Card::operator< (const Card& other)
{
	return number < other.number && suit == other.suit;
}
bool Card::operator<= (const Card& other)
{
	return *this < other || *this == other;
}
bool Card::operator> (const Card& other)
{
	return !(*this <= other);
}
bool Card::operator>= (const Card& other)
{
	return *this > other || *this == other;
}
bool Card::operator!= (const Card& other)
{
	return !(*this == other);
}