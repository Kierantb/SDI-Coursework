#pragma once
#include <vector>
#include "Item.h"
#include "PC.h"

class RegardItem
{
public:
	RegardItem();
	~RegardItem();
	void AddItem(Item* newItem);
	void AddPC(PC* newPC);
	vector<PC*>& GetAllPCs();
	vector<Item*>& GetAllItems(); // returns the current vector
	PC* CreatePC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory, 
								Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage); // single elements of specific vectors
	// FOCUS ON BUILD PC
	// Have function to return costs and profits
private:
	vector<Item*> _currentItems; // vector to hold employees in any format
	vector<PC*> _currentPCs;
};

