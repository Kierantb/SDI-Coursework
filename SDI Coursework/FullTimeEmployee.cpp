#include "stdafx.h"
#include "FullTimeEmployee.h"


FullTimeEmployee::FullTimeEmployee()
{
	_annualSalary = 0;
}

void FullTimeEmployee::SetWages(string newAnnualSalaray)
{
	_annualSalary = stof(newAnnualSalaray, 0);
}
float FullTimeEmployee::GetMonthlyPay()
{
	return _annualSalary / 12;
}
float FullTimeEmployee::GetWages()
{
	return _annualSalary;
}
FullTimeEmployee::~FullTimeEmployee()
{
}
