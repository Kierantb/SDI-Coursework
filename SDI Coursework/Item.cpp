#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	_type = "";
	_id = 0;
	_name = "";
	_buyPrice = 0;
	_sellPrice = 0;
}
void Item::SetType(string newType)
{
	_type = newType;
}
void Item::SetID(string newID)
{
	_id = stoi(newID);
}
void Item::SetName(string newName)
{
	_name = newName;
}
void Item::SetBuyPrice(string newBuyPrice)
{
	_buyPrice = stod(newBuyPrice, 0);
}
void Item::SetSellPrice(string newSellPrice)
{
	_sellPrice = stod(newSellPrice, 0);
}
string Item::GetType()
{
	return _type;
}
string Item::GetName()
{
	return _name;
}
double Item::GetBuyPrice()
{
	return _buyPrice;
}
double Item::GetSellPrice()
{
	return _sellPrice;
}
int Item::GetID()
{
	return _id;
}
Item::~Item()
{
}
