#pragma once
#include<string>
using namespace std;

class Person
{
public:
	Person();
	~Person();
private:
	int _id;
	string _firstName;
	string _lastName;
	string _postCode;
	string _houseNumber;
	string _email;
	int _mobileNumber;
};

