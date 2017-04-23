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
	string Person::GetName();

private:
	int _id;
	string _firstName;
	string _email;
};

