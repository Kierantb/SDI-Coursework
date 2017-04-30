#pragma once
#include "Customer.h"

class CustomerFactory
{
public:
	CustomerFactory();
	~CustomerFactory();
	Customer* CreateCustomer(string newCustomerRecord) const;
};

