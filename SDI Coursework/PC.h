#pragma once
#include "Item.h"

class PC
{
public:
	PC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory,
		Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage);
	~PC();
private:
	Item* _tower;
	Item* _motherboard;
	Item* _processor;
	Item* _memory;
	Item* _powerSupply;
	Item* _graphicsCard;
	Item* _storage;
};

