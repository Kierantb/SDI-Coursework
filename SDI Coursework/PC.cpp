#include "stdafx.h"
#include "PC.h"


PC::PC(Item* newTower, Item* newMotherboard, Item* newProcessor, Item* newMemory,
	Item* newPowerSupply, Item* newGraphicsCard, Item* newStorage)
{
	_tower = newTower;
	_motherboard = newMotherboard;
	_processor = newProcessor;
	_memory = newMemory;
	_powerSupply = newPowerSupply;
	_graphicsCard = newGraphicsCard;
	_storage = newStorage;
}


PC::~PC()
{
}
