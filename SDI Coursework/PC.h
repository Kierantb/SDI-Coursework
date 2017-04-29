#pragma once
#include "Item.h"
#include <vector>

class PC
{
public:
	PC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory,
		Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage);
	~PC();
	double GetPrice();
	vector<string> GetBuildInfo();
private:
	Item* _tower;
	Item* _motherboard;
	Item* _processor;
	Item* _memory;
	Item* _powerSupply;
	Item* _graphicsCard;
	Item* _storage;
};

