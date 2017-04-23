#include "stdafx.h"
#include "RegardEmployees.h"
#include <iostream>
using namespace std;


RegardEmployees::RegardEmployees()
{
}
void RegardEmployees::AddEmployee(Employee *newEmployee)
{
	_currentEmployees[5] = newEmployee;
}
void RegardEmployees::PrintEmployees()
{
	for (size_t i = 0; i < 5; i++)
	{
		cout << _currentEmployees[i] << endl;
	}
}
RegardEmployees::~RegardEmployees()
{
}
