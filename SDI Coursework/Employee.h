#pragma once
#include "Person.h"
class Employee :
	public Person
{
public:
	Employee();
	~Employee();
	void SetType(string newType);
	virtual void SetWages(string newHourlyWage);
	void SetHoursWorked(string newHoursWorked);
	string GetType();
	float GetHoursWorked();
	virtual float GetMonthlyPay(); // hourly pay * hours worked. Can be overridden by child class.
	virtual float GetWages();

private:
	string _type;
	float _hoursPerMonth;
	float _hourlyWage;
};

