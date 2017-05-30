#include "LibFunctions.h"

//problem #2
template <class T>
void printArray(const vector<T>& array);
template <class T>
void printArray(T* array, int rows);
template <class T>
void printArray(T** array, int rows, int columns);

int main()
{
	Cards hand;
	Card a(12,HEARTS), b(10, SPADES), c(4, DIAMONDS),
		d(7,HEARTS), e, f(3);
	hand.addCard(a);
	//hand.addCard(b);
	hand.addCard(c);
	//hand.addCard(d);
	hand.addCard(e);
	hand.addCard(f);

	cout << boolalpha << (evaluate(hand, 1) ==  WIN) << endl;
	cout << endl;
	//hand.print();

	vector<int> arr = { 1,2,3,4,5 };
	//printArray<int>(randomShuffle(arr));
}


template <class T>
void printArray(const vector<T>& array)
{
	if (array.empty())
		cout << "vector is empty" << endl;
	else
	{
		for (unsigned int i = 0; i < array.size(); i++)
			cout << setw(7) << array[i];
		cout << endl;
	}
}
template <class T>
void printArray(T* array, int rows)
{
	if (rows == 0)
		cout << "array is empty" << endl;
	else
	{
		for (int i = 0; i < rows; i++)
			cout << setw(7) << array[i];
		cout << endl;
	}
}
template <class T>
void printArray(T** array, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(7) << array[i][j];
		cout << endl;
	}
}
