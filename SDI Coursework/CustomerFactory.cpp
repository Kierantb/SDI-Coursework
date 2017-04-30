#include "stdafx.h"
#include "CustomerFactory.h"
#include <sstream>

CustomerFactory::CustomerFactory()
{
}

Customer* CustomerFactory::CreateCustomer(string newCustomerRecord) const
{
	Customer* temp = NULL;

	string customerInfo[4]; // type, id, name, email
	int i = 0;
	stringstream ssin(newCustomerRecord);
	while (ssin.good() && i < 4)
	{
		ssin >> customerInfo[i]; // each word read is set to an array element
		++i;
	}

	temp = new Customer();
	temp->SetMembership(customerInfo[0]);
	temp->SetID(customerInfo[1]);
	temp->SetFirstName(customerInfo[2]);
	temp->SetEmail(customerInfo[3]);

	return temp;
}

CustomerFactory::~CustomerFactory()
{
}
