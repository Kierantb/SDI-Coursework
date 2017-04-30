#include "stdafx.h"
#include "RegardItem.h"
using namespace std;
#include <iostream>

RegardItem::RegardItem()
{
	vector<Item*> _currentItems = { 0 };
	vector<PC*> _currentPCs = { 0 };

	vector<Item*> _towerCollection = { 0 };
	vector<Item*> _motherboardCollection = { 0 };
	vector<Item*> _processorCollection = { 0 };
	vector<Item*> _memoryCollection = { 0 };
	vector<Item*> _powerSupplyCollection = { 0 };
	vector<Item*> _graphicsCardCollection = { 0 };
	vector<Item*> _storageCollection = { 0 };
}
void RegardItem::AddItem(Item* newItem)
{
	_currentItems.push_back(newItem);
}
void RegardItem::AddPC(PC* newPC)
{
	_currentPCs.push_back(newPC);
}
vector<Item*>& RegardItem::GetAllItems() // maybe make const, const
{
	return _currentItems; // returns reference
}
vector<PC*>& RegardItem::GetAllPCs() // maybe make const, const
{
	return _currentPCs; // returns reference
}
vector<Item*>& RegardItem::GetTowerCollection()
{
	return _towerCollection;
}
vector<Item*>& RegardItem::GetMotherboardCollection()
{
	return _motherboardCollection;
}
double RegardItem::GetPCPrice(PC* pc)
{
	double price = pc->GetPrice();
	return price;
}
// write gets
PC* RegardItem::CreatePC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory,
	Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage)
{
	PC* tempPC = NULL;
	tempPC = new PC(newTower, newMotherboard, newProcessor, newMemory, newPowerSupply, newGraphicsCard, newStorage); // constructed
	return tempPC;
}
void RegardItem::SortItemType()
{
	size_t length = _currentItems.size();
	for (size_t i = 0; i < length; i++)
	{
		if (_currentItems[i]->GetType().compare("Tower") == 0)
		{
			_towerCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("Motherboard") == 0)
		{
			_motherboardCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("Processor") == 0)
		{
			_processorCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("Memory") == 0)
		{
			_memoryCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("PowerSupply") == 0)
		{
			_powerSupplyCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("GraphicsCard") == 0)
		{
			_graphicsCardCollection.push_back(_currentItems[i]);
		}
		else if (_currentItems[i]->GetType().compare("Storage") == 0)
		{
			_storageCollection.push_back(_currentItems[i]);
		}
	}

}
void RegardItem::BuildAllPCs()
{
	for (size_t i = 0; i < GetTowerCollection().size(); i++)
	{
		for (size_t j = 0; j < GetMotherboardCollection().size(); j++)
		{
			for (size_t k = 0; k < _processorCollection.size(); k++)
			{
				for (size_t l = 0; l < _memoryCollection.size(); l++)
				{
					for (size_t m = 0; m < _powerSupplyCollection.size(); m++)
					{
						for (size_t n = 0; n < _graphicsCardCollection.size(); n++)
						{
							for (size_t o = 0; o < _storageCollection.size(); o++)
							{
								PC* pc = CreatePC(_towerCollection[i], _motherboardCollection[j], _processorCollection[k], 
													_memoryCollection[l], _powerSupplyCollection[m], _graphicsCardCollection[n], _storageCollection[o]);
								AddPC(pc);
							}
						}
					}
				}
			}
		}
	}
}
void RegardItem::SortItemByID(vector<Item*> &unsortedItems) // shell sort as many items
{
	int length = unsortedItems.size();

	int i, j, gap;
	// gap would be considered half of length

	Item* temp;

	for (gap = length / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < length; i++)
		{
			for (j = i - gap; j >= 0 && unsortedItems[j]->GetID()>unsortedItems[j + gap]->GetID(); j -= gap)
			{
				temp = unsortedItems[j];
				unsortedItems[j] = unsortedItems[j + gap];
				unsortedItems[j + gap] = temp;
			}
		}
	}
}
Item* RegardItem::SearchItemByID(vector<Item*> &sortedItems, int searchValue)
{
	int length = sortedItems.size();
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2; // can lop off floating point value

		if (searchValue == sortedItems[mid]->GetID())
		{
			return sortedItems[mid]; // return the midpoint index if the search value is equal to the midpoint value
		}
		else if (searchValue > sortedItems[mid]->GetID())
		{
			low = mid + 1; // set new low point to the old mid point + 1 if the search value is greater than the midpoint value
		}
		else // <
		{
			high = mid - 1; // set new high point to the old mid point - 1 if the search value is less than the midpoint value
		}
	}
	return 0; // result might not exist - find better way to handle this
}
void RegardItem::RemoveBasketFromItems(vector<Item*> &customerBasket)
{
	for (size_t i = 0; i < _currentItems.size(); i++)
	{
		for (size_t j = 0; j < customerBasket.size(); j++)
		{
			if (customerBasket[j]->GetID == _currentItems[i]->GetID())
			{
				customerBasket.erase(customerBasket.begin() + j); // needs testing
			}
		}
	}
	// remove items in customer basket from current items then clear basket
}
RegardItem::~RegardItem()
{
}
