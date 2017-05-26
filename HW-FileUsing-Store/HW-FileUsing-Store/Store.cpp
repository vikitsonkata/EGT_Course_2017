#include "Store.h"



Store::Store()
{
}


Store::~Store()
{
}

Store::Store(const string& name)
{
	setName(name);
}

const string& Store::getName() const
{
	return this->name;
}
const vector<Item>& Store::getItems() const
{
	return this->items;
}

void Store::setName(const string& name)
{
	if (name.length() > 10)
	{
		int find = name.find(' ');
		this->name = name.substr(0, find);
	}
	else
		this->name = name;
}
void Store::setItems(const vector<Item>& items)
{
	if (!items.empty())
		this->items = items;
}

void Store::addItem(const Item& item)
{
	string name = item.getName();
	bool isNew = true;
	for (unsigned int i = 0; i < items.size() && isNew; i++)
		if (items[i].getName().compare(name) == 0)
		{
			items[i].addMore(item.getQuantity());
			isNew = false;
		}
	if (isNew)
		items.push_back(item);
}
double Store::calculatePriceOfItems()
{
	double sum = 0;
	for (unsigned int i = 0; i < items.size(); i++)
		sum += items[i].calculatePrice();
	return sum;
}