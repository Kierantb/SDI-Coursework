#include "stdafx.h"
#include "Person.h"

Person::Person()
{
	_id = 0;
	_firstName = "";
	_email = "";
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
int Person::GetID()
{
	return _id;
}
string Person::GetName()
{
	return _firstName;
}
string Person::GetEmail()
{
	return _email;
}
Person::~Person()
{
}
