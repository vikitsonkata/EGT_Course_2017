#include "LibFunctions.h"

//problem #2
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
	hand.print();
/*	if (evaluateHands(ab,cd) == FIRST)
		cout << "First wins" << endl;
	else if (evaluateHands(ab, cd) == SECOND)
		cout << "Second wins" << endl;
	else if (evaluateHands(ab, cd) == NOBODY)
		cout << "Nobody wins" << endl;
	else
		cout << "ERROR" << endl;
*///Dont work!!!

	//cout << divideWithReminder(12, 5) << endl;
	//Work !

	//cout << roundDouble(123.14, 2)<<endl;
	//cout << roundDouble(123.14, 1) << endl;
	//cout << roundDouble(123.14, 0) << endl;
	//cout << roundDouble(123.14, -1)<<endl;
	//cout << roundDouble(123.14, -2)<<endl;
	//Work!

//	int arr[5] = { 1,2,3,4,5 };
//	//int a[2][4] = { {1,2,3,4},{1,2,3,6} };
//	
//	int** a = new int*[2];
//	for (int i = 0; i < 2; i++)
//		a[i] = new int[4];
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 4; j++)
//			a[i][j] = i + j;
//
//	printArray<int>(arr, 5);
//	printArray<int>(a, 2, 4);
//
//
//	for (int i = 0; i < 2; i++)
//		delete[] a[i];
//	delete[] a;
	//Work!
}

template <class T>
void printArray(T* array, int rows)
{
	for (int i = 0; i < rows; i++)
		cout << setw(7) << array[i];
	cout << endl;
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
