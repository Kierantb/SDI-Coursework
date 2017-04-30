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
	vector<Item*>& GetTowerCollection();
	vector<Item*>& GetMotherboardCollection();
	double GetPCPrice(PC* pc);

	PC* CreatePC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory, 
								Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage);
	void SortItemType(); 
	void BuildAllPCs();
	void SortItemByID(vector<Item*> &unsortedItems);
	Item* SearchItemByID(vector<Item*> &sortedItems, int searchValue);

	void RemoveBasketFromItems(vector<Item*> &customerBasket);

private:
	vector<Item*> _currentItems; // vector to hold items
	vector<PC*> _currentPCs;

	vector<Item*> _towerCollection;
	vector<Item*> _motherboardCollection;
	vector<Item*> _processorCollection;
	vector<Item*> _memoryCollection;
	vector<Item*> _powerSupplyCollection;
	vector<Item*> _graphicsCardCollection;
	vector<Item*> _storageCollection;
};

// FOCUS ON BUILD PC
// Have function to return costs and profits