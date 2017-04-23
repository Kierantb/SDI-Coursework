#pragma once
#include "Employee.h"
class RegardEmployees
{
public:
	RegardEmployees();
	~RegardEmployees();
	void AddEmployee(Employee *newEmployee);
	void PrintEmployees();
private:
	Employee* _currentEmployees[5]; // could have a method to set employees capacity
};

