#ifndef LIBFUCTIONS
#define LIBFUNCTIOS

#include "Cards.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum WINNER { FIRST = 1 , SECOND, NOBODY = 0};
enum GAME_POKER { NO_COMBINATION, PAIR, TWO_PAIRS, THREE_OF_A_KIND,
	STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH};
enum GAME_BLACKJACK { PLAYING, WIN, BUST };

string toUpper(const string& symbols);
string currency(double number, const string& symbol);
string currency(const string& symbol, double number);

//template <class T>
//void printArray(T* array, int rows);
//
//template <class T>
//void printArray(T** array, int rows, int columns);

double roundDouble(double number, int pos);

string divideWithReminder(int, int);

//WINNER evaluateHands(const Cards&, const Cards&);

GAME_POKER evaluate(const Cards&);

GAME_BLACKJACK evaluate(const Cards&, int);
#endif