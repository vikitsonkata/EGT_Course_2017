#include "Item.h"

//int countOfItems = 0;


Item::Item()
{
	//countOfItems++;
	setAccountNumber(0);
	setQuantity(0);
	setName("");
	setPrice(0);
}


Item::~Item()
{
	//countOfItems--;
}


ostream& operator<<(ostream& os, const Item& other)
{
	os << other.accountNumber << " " << other.name << " "
		<< other.quantity << " " << other.pricePer;
	return os;
}
istream& operator>>(istream& is, Item& other)
{
	is >> other.accountNumber >> other.name
		>> other.quantity >> other.pricePer;
	return is;
}

Item::Item(int number, const string& name,
	int quantity, double pricePer)
{
	//countOfItems++;
	setAccountNumber(number);
	setName(name);
	setQuantity(quantity);
	setPrice(pricePer);
}

int Item::getAccountNumber() const
{
	return this->accountNumber;
}
const string& Item::getName() const
{
	return this->name;
}
int Item::getQuantity() const
{
	return this->quantity;
}
double Item::getPricePer() const
{
	return this->pricePer;
}

void Item::setAccountNumber(int number)
{
	this->accountNumber = number;
}
void Item::setName(const string& name)
{
	if (name.length() > 20)
	{
		int find = name.find(' ');
		this->name = name.substr(0, find);
	}
	else
		this->name = name;
}
void Item::setQuantity(int quantity)
{
	if (quantity < 0)
		this->quantity = 0;
	else 
		this->quantity = quantity;
}
void Item::setPrice(double pricePer)
{
	if (pricePer < 0)
		this->pricePer = 0;
	else
		this->pricePer = pricePer;
}

void Item::addMore(int quantity)
{
	if (quantity < 0)
		cout << "Don't streel!" << endl;
	else this->quantity += quantity;
}
double Item::calculatePrice()
{
	return quantity*pricePer;
}