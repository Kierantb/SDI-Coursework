#pragma once
#include "Employee.h"
#include <vector>

//#include <typeinfo>
//string s = typeid(YourClass).name() // gets class type

class RegardEmployees
{
public:
	RegardEmployees();
	~RegardEmployees();
	void AddEmployee(Employee * newEmployee);
	//void RemoveEmployee(int newID);
	vector<Employee*>& GetAllEmployees(); // returns the current vector

	void SortByID(vector<Employee*> &unsortedEmployees);
	Employee* SearchID(vector<Employee*> &sortedEmployees, int newID); // binary search as numbers used

private:
	vector<Employee*> _currentEmployees; // vector to hold employees in any format
};

