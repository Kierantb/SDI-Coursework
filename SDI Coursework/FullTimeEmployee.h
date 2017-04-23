#pragma once
#include "Employee.h"
class FullTimeEmployee :
	public Employee
{
public:
	FullTimeEmployee();
	~FullTimeEmployee();
	float GetMonthlyPay(); // annual wage / 12. Will override employee function.
private:
	float _annualSalary;
};

