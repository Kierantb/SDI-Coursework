#pragma once
#include "Person.h"
class Employee :
	public Person
{
public:
	Employee();
	~Employee();
	virtual float GetMonthlyPay(); // hourly pay * hours worked. Can be overridden by child class.
private:
	float _hoursWorked;
	float _hourlyWage;
};

