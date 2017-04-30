#include "stdafx.h"
#include "RegardCustomer.h"

RegardCustomer::RegardCustomer()
{
}
void RegardCustomer::AddCustomer(Customer* newCustomer)
{
	_currentCustomers.push_back(newCustomer);
}
vector<Customer*>& RegardCustomer::GetAllCustomers()
{
	return _currentCustomers;
}
Customer* RegardCustomer::GetCustomerByID(int newID)
{
	for (size_t i = 0; i < _currentCustomers.size(); i++)
	{
		if (newID == _currentCustomers[i]->GetID())
		{
			return _currentCustomers[i];
		}
	}
	return 0;
}
RegardCustomer::~RegardCustomer()
{
}
