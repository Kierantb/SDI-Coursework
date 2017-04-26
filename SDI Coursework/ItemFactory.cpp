#include "stdafx.h"
#include "ItemFactory.h"
#include <sstream>
#include "Tower.h"
#include "Motherboard.h"
#include "Processor.h"
#include "Memory.h"
#include "PowerSupply.h"
#include "GraphicsCard.h"
#include "Storage.h"

ItemFactory::ItemFactory()
{
}
Item* ItemFactory::CreateItem(string newItemRecord) const
{
	Item* newItem = 0;

	string itemInfo[5]; // type, id, name, email
	int i = 0;
	stringstream ssin(newItemRecord);
	while (ssin.good() && i < 5)
	{
		ssin >> itemInfo[i]; // each word read is set to an array element
		++i;
	}

	if (itemInfo[0].compare("Tower") == 0)
	{
		newItem = new Tower();
	}
	else if (itemInfo[0].compare("Motherboard") == 0)
	{
		newItem = new Motherboard();
	}
	else if (itemInfo[0].compare("Processor") == 0)
	{
		newItem = new Processor();
	}
	else if (itemInfo[0].compare("Memory") == 0)
	{
		newItem = new Memory();
	}
	else if (itemInfo[0].compare("PowerSupply") == 0)
	{
		newItem = new PowerSupply();
	}
	else if (itemInfo[0].compare("GraphicsCard") == 0)
	{
		newItem = new GraphicsCard();
	}
	else if (itemInfo[0].compare("Storage") == 0)
	{
		newItem = new Storage();
	}

	newItem->SetType(itemInfo[0]);
	newItem->SetID(itemInfo[1]);
	newItem->SetName(itemInfo[2]);
	newItem->SetBuyPrice(itemInfo[3]);
	newItem->SetSellPrice(itemInfo[4]);

	return newItem;
}

ItemFactory::~ItemFactory()
{
}
