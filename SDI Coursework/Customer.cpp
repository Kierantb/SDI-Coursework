#include "stdafx.h"
#include "Customer.h"


Customer::Customer()
{
	_isMember = false;
}
void Customer::SetMembership(string newMembershipDetails)
{
	if (newMembershipDetails.compare("True") == 0)
	{
		_isMember = true;
	}
	else
	{
		_isMember = false;
	}
}
bool Customer::GetMembership()
{
	return _isMember;
}
void Customer::AddItemToBasket(Item* newItem)
{
	_basket.push_back(newItem);
}
vector<Item*>& Customer::GetBasket()
{
	return _basket;
}
Customer::~Customer()
{
}
