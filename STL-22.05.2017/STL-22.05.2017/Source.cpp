#include <iostream>
#include <map>
#include <vector>
using namespace std;

void func1(int* arr, int SIZE)
{
	//map< int, int, less< int > > ...
	map< int, int >::iterator it;

	map< int, int > counters;


	for (int i = 0; i < SIZE; i++)
	{
		int key = arr[i];
		if (counters.find(key) != counters.end())
			counters[key]++;
		else
			counters[key] = 1;
	}

	for (it = counters.begin(); it != counters.end(); it++)
		cout << it->first << '\t' << it->second << endl;

}
void func2(int* arr, int SIZE)
{
	typedef map< int, int, less< int> > mymap;
	mymap counters;
	mymap::iterator it;

	vector< int > vec(arr, arr+SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		int key = arr[i];
		if (counters.find(key) != counters.end())
			counters[key]++;
		else
			counters[key] = 1;
	}

	for (it = counters.begin(); it != counters.end(); it++)
		if (it->second % 2)
		{
			for (unsigned int i = 0; i < vec.size(); i++)
				if (vec[i] == it->first)
				{
					vec.erase(vec.begin() + i);
					i--;
				}
		}

	for (unsigned int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

}
int main()
{
	int arr[] = { 1,2,4,1,2,33,2,3,2,33,4 };
	int SIZE = 11;
	func1(arr, SIZE);
	cout << endl;
	func2(arr, SIZE);
}