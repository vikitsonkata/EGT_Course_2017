#ifndef STORE
#define STORE

#include "Item.h"
#include <vector>
using namespace std;

class Store
{
public:
	Store();
	~Store();

	Store(const string& name);

	const string& getName() const;
	const vector<Item>& getItems() const;

	void setName(const string& name);
	void setItems(const vector<Item>& items);
	
	void addItem(const Item& item);
	double calculatePriceOfItems();
private:
	string name;
	vector<Item> items;
};

#endif