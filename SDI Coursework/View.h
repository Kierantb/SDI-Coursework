#pragma once
#include "Employee.h"

class View
{
public:
	View();
	~View();
	void DisplayEmployees(Employee *allEmployees, int size); // this is a pointer to an array
};

