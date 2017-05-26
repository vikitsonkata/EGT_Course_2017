#include "LibFunctions.h"
#include <cmath>
using std::pow;

//problem #1
string toUpper(const string& symbols)
{
	string newString(symbols);
	for (unsigned int i = 0; i < symbols.size(); ++i)
		if (symbols[i] >= 'a' && symbols[i] <= 'z')
			newString[i] += (-'a' + 'A');
	return newString;
}
string currency(double number, const string& symbol)
{
	string newString;
	string num = to_string(number);
	int i = num.find('.');
	num = num.substr(0, i + 3);
	newString.append(num);
	newString.append(" ");
	newString.append(toUpper(symbol));
	cout << newString << endl;
	return newString;
}
string currency(const string& symbol, double number)
{
	string newString;
	string num = to_string(number);
	int i = num.find('.');
	num = num.substr(0, i + 3);
	newString.append(num);
	newString.append(" ");
	newString.append(toUpper(symbol));
	cout << newString << endl;
	return newString;
}

//
//template <class T>
//void printArray(T* array, int rows)
//{
//	for (int i = 0; i < rows; i++)
//		cout << setw(7) << array[i];
//	cout << endl;
//}
//template <class T>
//void printArray(T** array, int rows, int columns)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//			cout << setw(7) << array[i][j];
//		cout << endl;
//	}
//}

//problem #3
double roundDouble(double number, int pos)
{
	if (pos >= 0)
	{
		int num = (int)number / pow(10, pos);
		return (double)num;
	}
	else
	{
		double num = number;
		num *= pow(10, -pos);
		num = (int)num;
		num = (double)num;
		num /= pow(10, -pos);
		return num;
	}
}

//problem #4
string divideWithReminder(int devisible, int devisor)
{
	string ans = "";
	ans.append("quotient: ");
	ans.append(to_string(devisible / devisor));
	ans.append("\treminder: ");
	ans.append(to_string(devisible - devisible / devisor * devisor));
	return ans;
}

//problem #5 ?

////NOT problem #6
//WINNER evaluateHands(const Cards& first, const Cards& second)
//{
//	//2, 2+2, 3, straight, flush, 3+2, 4, straight flush;
//	if (first > second)
//		return FIRST;
//	if (first < second)
//		return SECOND;
//	return NOBODY;
//}


//{
//	int first[13], second[13];
//	bool firstSuits = true, secondSuits = true;
//	for (int i = 0; i < 13; i++)
//	{
//		first[i] = 0;
//		second[i] = 0;
//	}
//	for (unsigned int i = 0; i < cards.size(); i++)
//	{
//		if (cards[i].getSuit() != cards[0].getSuit())
//			firstSuits = false;
//		if (other.cards[i].getSuit() != other.cards[0].getSuit())
//			firstSuits = false;
//		first[cards[i].getNumber() - 1]++;
//		second[other.cards[i].getNumber() - 1]++;
//	}
//	int combinationFirst = 0, combinationSecond = 0;
//	//combinations 0 - high card, 1 - pair, 2 - 2 pairs, 3 - three of a kind
//	//	4 - strait, 5 - flush, 6 - full house, 7 - four of a kind, 8 - straight flush
//	for (int i = 0; i < 13; i++)
//	{
//		if (first[i] == 2)
//			combinationFirst = 1;
//		if (second[i] == 2)
//			combinationSecond = 1;
//		if (first[i] == 3)
//			combinationFirst = 3;
//		if (second[i] == 3)
//			combinationSecond = 3;
//		if (first[i] == 4)
//			combinationFirst = 7;
//		if (second[i] == 4)
//			combinationSecond = 7;
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		if (first[i] == first[i + 1] == first[i + 2] == first[i + 3] == first[i + 4] == 1)
//			combinationFirst = combinationFirst > 4 ? combinationFirst : 4;
//		if (second[i] == second[i + 1] == second[i + 2] == second[i + 3] == second[i + 4] == 1)
//			combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
//	}
//	if (firstSuits)
//	{
//		if (combinationFirst == 4)
//			combinationFirst = 8;
//		combinationFirst = combinationFirst > 5 ? combinationFirst : 5;
//	}
//	if (secondSuits)
//	{
//		if (combinationSecond == 4)
//			combinationSecond = 8;
//		combinationSecond = combinationSecond > 4 ? combinationSecond : 4;
//	}
//
//	//2+2, 3+2 ??
//	if (combinationFirst == 1 || combinationFirst == 3)
//	{
//		bool firstFind = false; //find pair or three of a kind at least
//		for (int i = 0; i < 13; i++)
//		{
//			if (first[i] == 2 || first[i] == 3)
//				firstFind = true;
//			if (firstFind)
//				if (first[i] == 2)
//					if (combinationFirst == 1) // 2+2
//						combinationFirst = 2;
//					else
//						combinationFirst = 6; // 3+2
//				else
//					combinationFirst = 6;//2+3
//		}
//	}
//	if (combinationSecond == 1 || combinationSecond == 3)
//	{
//		bool firstFind = false; //find pair or two of a kind at least
//		for (int i = 0; i < 13; i++)
//		{
//			if (second[i] == 2 || second[i] == 3)
//				firstFind = true;
//			if (firstFind)
//				if (second[i] == 2)
//					if (combinationSecond == 1) // 2+2
//						combinationSecond = 2;
//					else
//						combinationSecond = 6; // 3+2
//				else
//					combinationSecond = 6;//2+3
//		}
//	}
//
//
//	if (combinationFirst < combinationSecond)
//		return true;
//	else
//		return false;
//}
//problem #6
GAME_POKER evaluate(const Cards& other)
{
	GAME_POKER value = NO_COMBINATION;
	int counters[13];
	bool suits = true;
	for (int i = 0; i < 13; i++)
		counters[i] = 0;
	for (unsigned int i = 0; i < other.getCards().size(); i++)
	{
		if (other.getCards()[i].getSuit() != other.getCards()[0].getSuit())
			suits = false;
		counters[other.getCards()[i].getNumber() - 1] ++;
	}
	if (suits)
		value = FLUSH;
	for (int i = 0; i < (13 - 4); i++)
		if (counters[i] == counters[i + 1] ==
			counters[i + 2] == counters[i + 3] ==
			counters[i + 4] == 1)
			if (value == FLUSH)
				value = STRAIGHT_FLUSH;
			else
				value = STRAIGHT;
	bool pair = false, three = false;
	for (int i = 0; i < 13; i++)
	{
		if (counters[i] == 2)
			if (three)
				value = FULL_HOUSE > value ? FULL_HOUSE : value;
			else if (pair)
				value = TWO_PAIRS > value ? TWO_PAIRS : value;
			else
			{
				value = PAIR > value ? PAIR : value;
				pair = true;
			}
		if (counters[i] == 3)
			if(pair)
				value = FULL_HOUSE > value ? FULL_HOUSE : value;
			else
			{
				value = THREE_OF_A_KIND > value ? THREE_OF_A_KIND : value;
				three = true;
			}
		if (counters[i] == 4)
			return FOUR_OF_A_KIND;
	}
	return value;
}
GAME_BLACKJACK evaluate(const Cards& other, int sth)
{
	int sum = 0;
	int aces = 0;
	for (unsigned int i = 0; i < other.getCards().size(); i++)
	{
		int value = other.getCards()[i].getNumber();
		if (value > 10)
			value = 10;
		if (value == 1)
		{
			value = 11;
			aces++;
		}
		sum += value;
	}
	while(aces && sum>21)
		sum-=10;

	if (sum < 21)
		return PLAYING;
	if (sum == 21)
		return WIN;
	if (sum > 21)
		return BUST;
	cerr << "Error - blackjack" << endl;
}

//probelem #6


