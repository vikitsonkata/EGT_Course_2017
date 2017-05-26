#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>
using namespace std;

class Item
{
	friend ostream& operator<<(ostream&, const Item&);
	friend istream& operator>>(istream&, Item&);
public:
	//static int countOfItems;

	Item();
	~Item();

	Item(int number, const string& name,
		int quantity, double pricePer);
	
	int getAccountNumber() const;
	const string& getName() const;
	int getQuantity() const;
	double getPricePer() const;

	void setAccountNumber(int number);
	void setName(const string& name);
	void setQuantity(int quantity);
	void setPrice(double pricePer);

	void addMore(int quantity);
	double calculatePrice();
private:
	int accountNumber;
	string name;
	int quantity;
	double pricePer;
};

#endif