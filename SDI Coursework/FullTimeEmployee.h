#pragma once
#include "Employee.h"
class FullTimeEmployee :
	public Employee
{
public:
	FullTimeEmployee();
	~FullTimeEmployee();
	void SetWages(string newAnnualSalaray);
	float GetMonthlyPay(); // annual wage / 12. Will override employee function.
	float GetWages();

private:
	float _annualSalary;
	float _hoursWorked;
};

