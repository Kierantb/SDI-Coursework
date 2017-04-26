#pragma once
#include "Item.h"
class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();
	Item* CreateItem(string newItemRecord) const;
};

