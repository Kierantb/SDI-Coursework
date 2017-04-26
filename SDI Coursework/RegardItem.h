#pragma once
#include <vector>
#include "Item.h"
class RegardItem
{
public:
	RegardItem();
	~RegardItem();
	vector<Item*>& GetAllItems(); // returns the current vector
	// FOCUS ON BUILD PC
	// Have function to return costs and profits
private:
	vector<Item*> _currentItems; // vector to hold employees in any format
};

