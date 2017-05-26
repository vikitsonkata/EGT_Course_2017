#include "Store.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void doBlankFile(int, const string& = "");

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const Item&);
int getAccount(const string& = ""); //dont need arg!

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int main()
{
	//doBlankFile(10, "Viki_shop.txt");

	fstream inOutCredit("Viki_shop.txt", ios::in | ios::out);

	if (!inOutCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	int choice;
	while ((choice = enterChoice()) != END)
	{
		switch (choice)
		{
		case PRINT:
			createTextFile(inOutCredit);
			break;
		case UPDATE:
			updateRecord(inOutCredit);
			break;
		case NEW:
			newRecord(inOutCredit);
			break;
		case DELETE: 
			deleteRecord(inOutCredit);
			break;
		default: 
			cerr << "Incorrect choice" << endl;
			break;
		} 

		inOutCredit.clear(); // reset end-of-file indicator
	} 

	/*Item apple("apple", 10, 0.5);
	apple.addMore(20);
	cout <<"Item \"" << apple.getName() << "\" is " 
		<< apple.calculatePrice() << " money" << endl;

	Store cornerShop("BILLA");
	cornerShop.addItem(apple);
	cornerShop.addItem(apple);
	cout << cornerShop.calculatePriceOfItems() << endl;
	cornerShop.addItem(apple);
	cout << cornerShop.calculatePriceOfItems() << endl;
	cout << endl;*/
}

void doBlankFile(int count, const string& name)
{
	if (name == "")
	{
		string name;
		cout << "Enter name: ";
		cin >> name;
		name.append(".txt");
	}
	ofstream myStore(name, ios::binary);
	
	//ofstream myStore("Viki_shop.txt", ios::binary);

	if (!myStore)
	{
		cerr << "File could not be opened!" << endl;
		exit(1);
	}

	Item blankStore;

	//cout << blankStore << endl;

	for (int i = 0; i < count; i++)
		myStore.write(reinterpret_cast<const char*>(&blankStore), sizeof(Item));
}


//////////////////////////////////////////////////////////
int enterChoice()
{
	cout << "\nEnter your choice" << endl
		<< "1 - store a formatted text file of accounts" << endl
		<< "    called \"print.txt\" for printing" << endl
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - delete an account" << endl
		<< "5 - end program\n? ";

	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void createTextFile(fstream &readFromFile)
{
	// create text file
	ofstream outPrintFile("print.txt", ios::out);
	if (!outPrintFile)
	{
		cerr << "File could not be created." << endl;
		exit(1);
	}
	outPrintFile << left << setw(10) << "Account"
		<< left << setw(23) << "Name" 
		<< left << setw(15) << "Quantity" 
		<< right << setw(10) << "Price per 1" << endl;

	readFromFile.seekg(0);

	Item client;
	readFromFile.read(reinterpret_cast< char * >(&client),
		sizeof(Item));

	// copy all records from record file into text file
	while (!readFromFile.eof())
	{
		// write single record to text file
		if (client.getName() != "") // skip empty records
			outputLine(outPrintFile, client);

		// read next record from record file
		readFromFile.read(reinterpret_cast< char * >(&client),
			sizeof(Item));
	} // end while
} // end function createTextFile

  // update balance in record
void updateRecord(fstream &updateFile)
{
	int accountNumber = getAccount("Enter account to update");

	// move file-position pointer to correct record in file
	updateFile.seekg((accountNumber - 1) * sizeof(Item));

	// read first record from file	
	Item client;
	updateFile.read(reinterpret_cast< char * >(&client),
		sizeof(Item));

	// update record
	if (client.getAccountNumber() != 0)
	{
		outputLine(cout, client); // display the record

								  // request user to specify transaction
		cout << "\nEnter charge (+) or quantity (-): ";
		double transaction; // charge or payment
		cin >> transaction;

		// update record balance
		int oldQuantity = client.getQuantity();
		client.setQuantity(oldQuantity + transaction);
		outputLine(cout, client); // display the record

								  // move file-position pointer to correct record in file
		updateFile.seekp((accountNumber - 1) * sizeof(Item));

		// write updated record over old record in file
		updateFile.write(reinterpret_cast< const char * >(&client),
			sizeof(Item));
	} // end if
	else // display error if account does not exist
		cerr << "Account #" << accountNumber
		<< " has no information." << endl;
} // end function updateRecord

  // create and insert record
void newRecord(fstream &insertInFile)
{
	// obtain number of account to create
	int accountNumber = getAccount("Enter new account number");

	// move file-position pointer to correct record in file
	insertInFile.seekg((accountNumber - 1) * sizeof(Item));

	// read record from file
	Item client;
	insertInFile.read(reinterpret_cast< char * >(&client),
		sizeof(Item));

	cout << client << endl;

	// create record, if record does not previously exist
	if (client.getAccountNumber() == 0)
	{
		string name;
		int quantity;
		double pricePer;

		// user enters last name, first name and balance
		cout << "Enter name, quantity, price per 1\n? ";
		cin >> setw(23) >> name;
		cin >> setw(10) >> quantity;
		cin >> pricePer;

		// use values to populate account values
		client.setName(name);
		client.setQuantity(quantity);
		client.setPrice(pricePer);
		client.setAccountNumber(accountNumber);


		cout << client;
		cout << sizeof(Item);
		// move file-position pointer to correct record in file
		insertInFile.seekp((accountNumber - 1) * sizeof(Item));

		cout << client;

		// insert record in file                       
		insertInFile.write(reinterpret_cast< const char * >(&client),
			sizeof(Item));
	} // end if
	else // display error if account already exists
		cerr << "Account #" << accountNumber
		<< " already contains information." << endl;
} // end function newRecord

  // delete an existing record
void deleteRecord(fstream &deleteFromFile)
{
	// obtain number of account to delete
	int accountNumber = getAccount("Enter account to delete");

	// move file-position pointer to correct record in file
	deleteFromFile.seekg((accountNumber - 1) * sizeof(Item));

	// read record from file
	Item client;
	deleteFromFile.read(reinterpret_cast< char * >(&client),
		sizeof(Item));

	// delete record, if record exists in file
	if (client.getAccountNumber() != 0)
	{
		Item blankClient; // create blank record

		// move file-position pointer to correct record in file
		deleteFromFile.seekp((accountNumber - 1) *
			sizeof(Item));

		// replace existing record with blank record
		deleteFromFile.write(
			reinterpret_cast< const char * >(&blankClient),
			sizeof(Item));

		cout << "Account #" << accountNumber << " deleted.\n";
	} // end if
	else // display error if record does not exist
		cerr << "Account #" << accountNumber << " is empty.\n";
} // end deleteRecord

  // display single record
void outputLine(ostream &output, const Item &record)
{
	output << left << setw(10) << "Account"

		<< left << setw(23) << record.getName()

		<< left << setw(15) << record.getQuantity()

		<< right << fixed << showpoint << setw(10) 
		<< setprecision(2) << record.getPricePer() << endl;
} 

  // obtain account-number value from user
int getAccount(const string& prompt)
{
	int accountNumber;

	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);

	return accountNumber;
} // end function getAccount


