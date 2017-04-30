#pragma once
#include "Person.h"
#include "Item.h"
#include <vector>
class Customer :
	public Person
{
public:
	Customer();
	~Customer();
	void SetMembership(string newMembershipDetails);
	bool GetMembership();
	void AddItemToBasket(Item* newItem);
	vector<Item*>& GetBasket();

private:
	bool _isMember;
	vector<Item*> _basket;
};

