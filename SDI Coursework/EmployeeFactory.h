#pragma once
#include<string>
#include "Employee.h"

class EmployeeFactory
{
public:
	EmployeeFactory();
	~EmployeeFactory();
	Employee* CreateEmployee(string newEmployeeRecord) const;  // param is vector element

};

