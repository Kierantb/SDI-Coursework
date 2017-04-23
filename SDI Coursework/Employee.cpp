#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
}
float Employee::GetMonthlyPay()
{
	return _hoursWorked * _hourlyWage;
}
Employee::~Employee()
{
}
