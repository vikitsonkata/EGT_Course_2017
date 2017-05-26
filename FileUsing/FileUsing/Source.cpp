#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

void file1()
{
	ofstream outclient("clients.dat", ios::out);

	if (!outclient)
	{
		cout << "file could not be fount" << endl;
		exit(1);
	}

	int account;
	char name[30];
	double balance;

	cout << "enter account, name and balance" << endl;

	while (cin >> account >> name >> balance)
	{
		outclient << account << ' ' << name << ' ' << balance;
		cout << '?';
	} // while untill enter ctr+z
}
void file2()
{
	ofstream outClient("names.txt", ios::out);
	//ios::app append
	//ios::ate appent to the possision...
	//ios::in 
	//ios::out
	//ios::trunk ???
	//ios::binary ???
	//(file).eof() function to "end of file"
	//(file).clear() reset eof for next input
	//(file).seekg(0) reposition to begging

	if (!outClient)
	{
		cerr << "File could not be fount" << endl;
		exit(1);
	}

	char name[30];
	char lastName[30];
	int EGN;

	cout << "enter names and EGN" << endl;

	while (cin >> name >> lastName >> EGN)
	{
		outClient << name << ' ' << lastName << ' ' << EGN << endl;
		cout << '?';
	} // while untill enter ctr+z
	
}
void file3(const string& fileName)
{
	ifstream inObject(fileName, ios::in);

	if (!inObject)
	{
		cerr << "File could not be fount" << endl;
		exit(1);
	}

	string name;
	double balance;

	//while (!inObject.eof())
	int i = 0; 
	while(i<3)
	{
		i++;
		inObject >> name;
		inObject.seekg(4, ios::cur);
		inObject >> balance;
		inObject.seekg(5, ios::cur);
		cout << name << ' '
			<< balance <<  endl;
	}
}
double file4(const string& fileName)
{
	ifstream inObject(fileName, ios::in);
	if (!inObject)
	{
		cerr << "File could not be fount" << endl;
		exit(1);
	}


	int number;
	string name;
	int year;
	double price;

	double sum = 0;
	while (inObject >> number >> name >> year >> price)
	{
		cout << name << ' ';
		sum += price;
	}
	cout << endl;
	return sum;
}

int main()
{
	file3("newFile.txt");
	cout << endl;
	cout<<file4("Books.txt")<<endl;
}
