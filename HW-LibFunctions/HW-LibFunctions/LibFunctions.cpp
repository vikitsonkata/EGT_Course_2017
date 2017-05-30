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
string currency(double number, const char* symbol)
{
	string newString;
	string num = to_string(number);
	int i = num.find('.');
	num = num.substr(0, i + 3);
	newString.append(num);
	newString.append(" ");
	if(symbol == "usd" || symbol == "USD")
		newString.append("$"); 
	else if(symbol == "bgn" || symbol == "BGN") 
		newString.append("lv");
	else if (symbol == "eur" || symbol == "EUR")
		newString.append("ˆ"); 
	else
		newString.append(toUpper(symbol));
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
	if (symbol == "usd" || symbol == "USD")
		newString.append("$");
	else if (symbol == "bgn" || symbol == "BGN")
		newString.append("lv");
	else if (symbol == "eur" || symbol == "EUR")
		newString.append("ˆ");
	else
		newString.append(toUpper(symbol));
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
		int num = (int)number / pow(10, pos-1);
		num += 5;
		num /= 10;
		return (double)num;
	}
	else
	{
		double num = number;
		num *= pow(10, -pos);
		num += 0.5;
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

//problem #5 
int random(int obj) // picking random object < T (operator<)
{
	srand(time(NULL));
	return rand() % obj;
}
char random(char obj) // picking random object < T (operator<)
{
	srand(time(NULL));
	return (char)(rand() % obj)	;
}
vector<int> random(vector<int> arr) // picking random object/objects from arr, max length = int
{
	if (arr.empty())
		return arr;
	unsigned int size = arr.size();
	srand(time(NULL));
	int index1 = rand() % size, index2 = index1 + rand() % (size - index1);
	vector<int> toReturn;
	for (unsigned int i = index1; i < size; i++)
		toReturn.push_back(arr[i]);
	return toReturn;
}
template <class T>
vector<T> randomShuffle(vector<T> arr)
{
	unsigned int size = arr.size();
	srand(time(NULL));
	vector<T> toReturn;
	vector<int> indexes;
	unsigned int elementsReady = 0;
	for (unsigned int i = rand() % size; elementsReady<size; i = rand()%size;)
	{
		bool find = false;
		for (unsigned int j = 0; j < indexes.size(); j++)
			if (j == indexes[i])
			{
				find = true;
				elementsReady++;
			}
		if(!find)
			indexes.push_back(i);
	}
	for (unsigned int i = 0; i < size; i++)
		toReturn.push_back(arr[indexes[i]]);
	return toReturn;
}

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
	else if (sum == 21)
		return WIN;
	else if (sum > 21)
		return BUST;
	else
		return BUST;
	cerr << "Error - blackjack" << endl;
}

//probelem #6


