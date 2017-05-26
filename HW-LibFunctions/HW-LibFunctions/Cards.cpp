#include "Cards.h"

Cards::Cards()
{
	game = BLACKJACK;
}


Cards::~Cards()
{
}

Cards::Cards(const vector<Card>& cards)
{
	setCards(cards);
	game = BLACKJACK;
}

void Cards::setCards(const vector<Card>& cards)
{
	this->cards = cards;
}
void Cards::setGAME(GAME game)
{
	this->game = game;
}

const vector<Card>& Cards::getCards() const
{
	return this->cards;
}
GAME Cards::getGAME() const
{
	return game;
}

void Cards::addCard(const Card& card)
{
	cards.push_back(card);
}
void Cards::print() const
{
	for (unsigned int i = 0; i < cards.size(); i++)
		cards[i].print();
}

bool Cards::operator!=(const Cards& other) const
{
	if (cards.size() != other.cards.size())
		return true;
	return false;
}
bool Cards::operator==(const Cards& other) const
{
	return (!(*this < other) && !(*this > other));
}
bool Cards::operator<=(const Cards& other) const
{
	return !(*this > other);
}
bool Cards::operator>=(const Cards& other) const
{
	return !(*this < other);
}
bool Cards::operator<(const Cards& other) const
{
	if (*this != other)
		cerr << "Not comparable" << endl;
	if (cards.size() == 2)
	{
		int first = 0,	second = 0;
		for (int i = 0; i < cards.size(); i++)
			first += cards[i].getNumber()>9 ? 10:cards[i].getNumber();

		for (int i = 0; i < other.cards.size(); i++)
			second += other.cards[i].getNumber()>9 ? 10 : other.cards[i].getNumber();
		if (first < second && first <= 21)
			return true;
		else 
			return false;
	}
	else if (cards.size() == 5)
	{
		int first[13], second[13];
		bool firstSuits = true, secondSuits = true;
		for (int i = 0; i < 13; i++)
		{
			first[i] = 0;
			second[i] = 0;
		}
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			if (cards[i].getSuit() != cards[0].getSuit())
				firstSuits = false;
			if (other.cards[i].getSuit() != other.cards[0].getSuit())
				firstSuits = false;
			first[cards[i].getNumber() - 1]++;
			second[other.cards[i].getNumber() - 1]++;
		}
		int combinationFirst = 0, combinationSecond = 0;
		//combinations 0 - high card, 1 - pair, 2 - 2 pairs, 3 - three of a kind
		//	4 - strait, 5 - flush, 6 - full house, 7 - four of a kind, 8 - straight flush
		for (int i = 0; i < 13; i++)
		{
			if (first[i] == 2)
				combinationFirst = 1;
			if (second[i] == 2)
				combinationSecond = 1;
			if (first[i] == 3)
				combinationFirst = 3;
			if (second[i] == 3)
				combinationSecond = 3;
			if (first[i] == 4)
				combinationFirst = 7;
			if (second[i] == 4)
				combinationSecond = 7;
		}
		for (int i = 0; i < 9; i++)
		{
			if (first[i] == first[i + 1] == first[i + 2] == first[i + 3] == first[i + 4] == 1)
				combinationFirst = combinationFirst > 4 ? combinationFirst : 4;
			if (second[i] == second[i + 1] == second[i + 2] == second[i + 3] == second[i + 4] == 1)
				combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
		}
		if (firstSuits)
		{
			if (combinationFirst == 4)
				combinationFirst = 8;
			combinationFirst = combinationFirst > 5 ? combinationFirst : 5;
		}
		if (secondSuits)
		{
			if (combinationSecond == 4)
				combinationSecond = 8;
			combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
		}

		//2+2, 3+2 ??
		if (combinationFirst == 1 || combinationFirst == 3)
		{
			bool firstFind = false; //find pair or three of a kind at least
			for (int i = 0; i < 13; i++)
			{
				if (first[i] == 2 || first[i] == 3)
					firstFind = true;
				if (firstFind)
					if (first[i] == 2)
						if (combinationFirst == 1) // 2+2
							combinationFirst = 2;
						else
							combinationFirst = 6; // 3+2
					else
						combinationFirst = 6;//2+3
			}
		}
		if (combinationSecond == 1 || combinationSecond == 3)
		{
			bool firstFind = false; //find pair or two of a kind at least
			for (int i = 0; i < 13; i++)
			{
				if (second[i] == 2 || second[i] == 3)
					firstFind = true;
				if (firstFind)
					if (second[i] == 2)
						if (combinationSecond == 1) // 2+2
							combinationSecond = 2;
						else
							combinationSecond = 6; // 3+2
					else
						combinationSecond = 6;//2+3
			}
		}
		

		if (combinationFirst < combinationSecond)
			return true;
		else
			return false;
	}
}
bool Cards::operator>(const Cards& other) const
{
	if (*this != other)
		cerr << "Not comparable" << endl;
	if (cards.size() == 2)
	{
		int first = 0, second = 0;
		for (int i = 0; i < cards.size(); i++)
			first += cards[i].getNumber()>9 ? 10 : cards[i].getNumber();

		for (int i = 0; i < other.cards.size(); i++)
			second += other.cards[i].getNumber()>9 ? 10 : other.cards[i].getNumber();
		if (first < second && first <= 21)
			return true;
		else
			return false;
	}
	if (cards.size() == 5)
	{
		int first[13], second[13];
		bool firstSuits = true, secondSuits = true;
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			if (cards[i].getSuit() != cards[0].getSuit())
				firstSuits = false;
			if (other.cards[i].getSuit() != other.cards[0].getSuit())
				firstSuits = false;
			first[cards[i].getNumber() - 1]++;
			second[other.cards[i].getNumber() - 1]++;
		}
		int combinationFirst = 0, combinationSecond = 0;
		//combinations 0 - high card, 1 - pair, 2 - 2 pairs, 3 - three of a kind
		//	4 - strait, 5 - flush, 6 - full house, 7 - four of a kind, 8 - straight flush
		for (int i = 0; i < 13; i++)
		{
			if (first[i] == 2)
				combinationFirst = 1;
			if (second[i] == 2)
				combinationSecond = 1;
			if (first[i] == 3)
				combinationFirst = 3;
			if (second[i] == 3)
				combinationSecond = 3;
			if (first[i] == 4)
				combinationFirst = 7;
			if (second[i] == 4)
				combinationSecond = 7;
		}
		for (int i = 0; i < 9; i++)
		{
			if (first[i] == first[i + 1] == first[i + 2] == first[i + 3] == first[i + 4] == 1)
				combinationFirst = combinationFirst > 4 ? combinationFirst : 4;
			if (second[i] == second[i + 1] == second[i + 2] == second[i + 3] == second[i + 4] == 1)
				combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
		}
		if (firstSuits)
		{
			if (combinationFirst == 4)
				combinationFirst = 8;
			combinationFirst = combinationFirst > 5 ? combinationFirst : 5;
		}
		if (secondSuits)
		{
			if (combinationSecond == 4)
				combinationSecond = 8;
			combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
		}

		//2+2, 3+2 ??
		if (combinationFirst == 1 || combinationFirst == 3)
		{
			bool firstFind = false; //find pair or three of a kind at least
			for (int i = 0; i < 13; i++)
			{
				if (first[i] == 2 || first[i] == 3)
					firstFind = true;
				if (firstFind)
					if (first[i] == 2)
						if (combinationFirst == 1) // 2+2
							combinationFirst = 2;
						else
							combinationFirst = 6; // 3+2
					else
						combinationFirst = 6;//2+3
			}
		}
		if (combinationSecond == 1 || combinationSecond == 3)
		{
			bool firstFind = false; //find pair or two of a kind at least
			for (int i = 0; i < 13; i++)
			{
				if (second[i] == 2 || second[i] == 3)
					firstFind = true;
				if (firstFind)
					if (second[i] == 2)
						if (combinationSecond == 1) // 2+2
							combinationSecond = 2;
						else
							combinationSecond = 6; // 3+2
					else
						combinationSecond = 6;//2+3
			}
		}


		if (combinationFirst > combinationSecond)
			return true;
		else
			return false;
	}
}