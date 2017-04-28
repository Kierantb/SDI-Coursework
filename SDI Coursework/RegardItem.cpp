#include "stdafx.h"
#include "RegardItem.h"


RegardItem::RegardItem()
{
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
PC* RegardItem::CreatePC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory,
	Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage)
{
	PC* tempPC = NULL;
	tempPC = new PC(newTower, newMotherboard, newProcessor, newMemory, newPowerSupply, newGraphicsCard, newStorage); // constructed
	return tempPC;
}
RegardItem::~RegardItem()
{
}
