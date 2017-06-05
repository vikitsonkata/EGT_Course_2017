#include "LibFunctions.h"
#include <stdio.h>

//problem #2
template <class T>
void printArray(const vector<T>& array);
template <class T>
void printArray(T* array, int rows);
template <class T>
void printArray(T** array, int rows, int columns);



//int frequency_of_primes(int n) {
//	int i, j;
//	int freq = n - 1;
//	for (i = 2; i <= n; ++i) for (j = sqrt(i); j>1; --j) if (i%j == 0) { --freq; break; }
//	return freq;
//}

int main()
{
	{
		Cards hand;
		Card a(12, HEARTS), b(10, SPADES), c(4, DIAMONDS),
			d(7, HEARTS), e;
		hand.addCard(a);
		//hand.addCard(b);
		hand.addCard(c);
		//hand.addCard(d);
		hand.addCard(e);

		cout << boolalpha << (evaluate(hand, 1) == WIN) << endl;
		cout << endl;
		hand.print();

		vector<int> arr = { 1,2,3,4,5 };
		printArray<int>(arr);

		cout << endl;
	}
	{
		Rational rat, rat1(3, 6), rat2(3);
		cout << rat << endl
			<< rat1 << endl
			<< rat2 << endl;
	//	cout << "Enter rational number ";
	//	cin >> rat;
		cout << rat + rat1 << endl
			<< rat - rat1 << endl
			<< rat* rat1 << endl
			<< rat / rat1 << endl;
	}
	{
		ComplexNumber com, com1(1, 1), com2(2);
		cout << com << endl
			<< com1 << endl
			<< com2 << endl;
		//cout << "Enter complex number ";
		//cin >> com;
		cout << com + com1 << endl
			<< com - com1 << endl
			<< com*com1 << endl
			<< com / com1 << endl; 
	}
	{
		Point p1;
		p1.x = 3;
		p1.y = 4;
		Rectangle rec(0, 0, 0, 4, 4, 4, 4, 0);
		Rectangle rec2(p1, p1, p1, p1);
		Rectangle rec3(2, 0, 4, 1, 3, 3, 1, 2);
		//cout << rec.test() << endl;

		cout << rec2 << endl
			<< "area: " << rec2.area() << endl
			<< "perimeter: " << rec2.perimeter() << endl;
		cout << "up left corner: " << rec2.upLeftCorner().x << " " << rec2.upLeftCorner().y << endl;
		cout << "rec2 center: " << rec2.center()->x << " " << rec2.center()->y << endl;
		cout << "rec center: " << rec.center()->x << " " << rec.center()->y << endl;
		delete rec.center(), rec2.center();

		//rec.show('#', ' ', 0, 0);
		rec.show();
		//rec3.show('#', '*', 3, 14);
		rec3.show('#', '*');

		cout << endl;
	}
	{
		HugeInteger num1, num2;
		//num1.input();
		num1.output();
		//num2.input();
		num1.add(num2).output();
		num1.substract(num2).output();
		num1.multiply(num2).output();
		//num1.divide(num2).output(); 
	}
	{
		IntegerSet intset;
		intset.insertElement(3);
		intset.insertElement(4);
		intset.insertElement(6);
		intset.insertElement(6);
		intset.insertElement(31);
		intset.print();
		intset.deleteElement(4);
		cout << intset << endl;
	}


	/*{
	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 12;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 117; y2k.tm_mon = 5; y2k.tm_mday = 31;

	time(&timer);

	seconds = difftime(timer, mktime(&y2k));

	cout << seconds << " seconds since 12:00:00 May 31, 2017 in the current timezone" << endl;



	clock_t t;
	int f;
	t = clock();
	printf("Calculating...\n");
	f = frequency_of_primes(99999);
	printf("The number of primes lower than 100,000 is: %d\n", f);
	t = clock() - t;
	printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	}*/

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
