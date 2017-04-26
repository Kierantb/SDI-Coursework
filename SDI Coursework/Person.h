#pragma once
#include<string>
using namespace std;

class Person
{
public:
	Person();
	~Person();
	void Person::SetID(string newID);
	void Person::SetFirstName(string newName);
	void Person::SetEmail(string newName);
	int Person::GetID();
	string Person::GetName();
	string Person::GetEmail();

private:
	int _id;
	string _firstName;
	string _email;
};

