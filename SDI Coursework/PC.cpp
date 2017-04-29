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

double PC::GetPrice()
{
	double price = _tower->GetSellPrice() + _motherboard->GetSellPrice() + _processor->GetSellPrice() + _memory->GetSellPrice()
		+ _powerSupply->GetSellPrice() + _graphicsCard->GetSellPrice() + _storage->GetSellPrice();
	return price;
}
vector<string> PC::GetBuildInfo()
{
	vector<string> info;
	info.push_back(_tower->GetName());
	info.push_back(_motherboard->GetName());
	info.push_back(_processor->GetName());
	info.push_back(_memory->GetName());
	info.push_back(_powerSupply->GetName());
	info.push_back(_graphicsCard->GetName());
	info.push_back(_storage->GetName());
	return info;
}
PC::~PC()
{
}
