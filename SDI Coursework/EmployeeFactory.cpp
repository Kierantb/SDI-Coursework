#include "stdafx.h"
#include "EmployeeFactory.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "TemporaryEmployee.h"
#include <sstream>

EmployeeFactory::EmployeeFactory()
{
}
Employee* EmployeeFactory::CreateEmployee(string newEmployeeRecord) const
{
	Employee* newEmployee = 0;

	string employeeInfo[4]; // type, id, name, email
	int i = 0;
	stringstream ssin(newEmployeeRecord);
	while (ssin.good() && i < 4)
	{
		ssin >> employeeInfo[i]; // each word read is set to an array element
		++i;
	}

	if (employeeInfo[0].compare("FullTimeEmployee") == 0)
	{
		newEmployee = new FullTimeEmployee();
	}
	else if (employeeInfo[0].compare("PartTimeEmployee") == 0)
	{
		newEmployee = new PartTimeEmployee();
	}
	else if (employeeInfo[0].compare("TemporaryEmployee") == 0)
	{
		newEmployee = new TemporaryEmployee();
	}

	newEmployee->SetID(employeeInfo[1]);
	newEmployee->SetFirstName(employeeInfo[2]);
	newEmployee->SetEmail(employeeInfo[3]);

	return newEmployee; 
}
EmployeeFactory::~EmployeeFactory()
{
}
