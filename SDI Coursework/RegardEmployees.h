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
	void AddEmployee(Employee* newEmployee);
	void DeleteEmployee(Employee* newEmployee);
	vector<Employee*>& GetAllEmployees(); // returns the current vector

	void SortByID(vector<Employee*> &unsortedEmployees); // bubble sort
	Employee* SearchID(vector<Employee*> &sortedEmployees, int newID); // binary search as numbers used
	Employee* SearchName(vector<Employee*> &employees, string newName); // linear search by name

	// Have function to return costs and profits

private:
	vector<Employee*> _currentEmployees; // vector to hold employees in any format
};

