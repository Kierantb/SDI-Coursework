#pragma once
#include "Customer.h"
#include <vector>
class RegardCustomer
{
public:
	RegardCustomer();
	~RegardCustomer();
	void AddCustomer(Customer* newCustomer);
	vector<Customer*>& GetAllCustomers();
	Customer* GetCustomerByID(int newID);
private:
	vector<Customer*> _currentCustomers;
};

