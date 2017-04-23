#include "stdafx.h"
#include "FullTimeEmployee.h"


FullTimeEmployee::FullTimeEmployee()
{
}
float FullTimeEmployee::GetMonthlyPay()
{
	return _annualSalary / 12;
}
FullTimeEmployee::~FullTimeEmployee()
{
}
