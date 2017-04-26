#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
	_type = "";
	_hoursPerMonth = 0;
	_hourlyWage = 0;
}
void Employee::SetType(string newType)
{
	_type = newType;
}
void Employee::SetWages(string newHourlyWage)
{
	_hourlyWage = stof(newHourlyWage, 0);
}
void Employee::SetHoursWorked(string newHoursWorked)
{
	_hoursPerMonth = stof(newHoursWorked, 0);
}
string Employee::GetType()
{
	return _type;
}
float Employee::GetHoursWorked()
{
	return _hoursPerMonth;
}
float Employee::GetMonthlyPay()
{
	return _hoursPerMonth * _hourlyWage;
}
float Employee::GetWages()
{
	return _hourlyWage;
}
Employee::~Employee()
{
}
