#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}
void Person::SetID(string newID)
{
	_id = stoi(newID);
}
void Person::SetFirstName(string newFirstName)
{
	_firstName = newFirstName;
}
void Person::SetEmail(string newEmail)
{
	_email = newEmail;
}
string Person::GetName()
{
	return _firstName;
}
Person::~Person()
{
}
