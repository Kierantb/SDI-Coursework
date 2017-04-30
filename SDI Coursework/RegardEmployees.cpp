#include "stdafx.h"
#include "RegardEmployees.h"
#include <iostream>
#include <vector>
#include <algorithm> // find
using namespace std;


RegardEmployees::RegardEmployees()
{
}
void RegardEmployees::AddEmployee(Employee* newEmployee)
{
	_currentEmployees.push_back(newEmployee);
}
void RegardEmployees::DeleteEmployee(Employee* newEmployee) // maybe make bool
{
	vector<Employee*>::iterator index = find(_currentEmployees.begin(), _currentEmployees.end(), newEmployee);
	if (index != _currentEmployees.end())
	{
		_currentEmployees.erase(index);
	}
}
vector<Employee*>& RegardEmployees::GetAllEmployees() // maybe make const, const
{
	return _currentEmployees; // returns reference
}
void RegardEmployees::SortByID(vector<Employee*> &unsortedEmployees) 
{
	int length = unsortedEmployees.size();

	for (size_t i = length - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (unsortedEmployees[j]->GetID() > unsortedEmployees[j + 1]->GetID()) // bubble sort
			{
				Employee *temp = unsortedEmployees[j];
				unsortedEmployees[j] = unsortedEmployees[j + 1];
				unsortedEmployees[j + 1] = temp;
			}
		}
	}
}
Employee* RegardEmployees::SearchID(vector<Employee*> &sortedEmployees, int newID) // binary search
{
	int length = sortedEmployees.size();
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2; // can lop off floating point value

		if (newID == sortedEmployees[mid]->GetID())
		{
			return sortedEmployees[mid]; // return the midpoint index if the search value is equal to the midpoint value
		}
		else if (newID > sortedEmployees[mid]->GetID())
		{
			low = mid + 1; // set new low point to the old mid point + 1 if the search value is greater than the midpoint value
		}
		else // <
		{
			high = mid - 1; // set new high point to the old mid point - 1 if the search value is less than the midpoint value
		}
	}
	return 0; // result might not exist - find better way to handle this
}

Employee* RegardEmployees::SearchName(vector<Employee*> &employees, string newName) // binary search
{
	size_t length = employees.size();
	for (size_t i = 0; i < length; i++)
	{
		if (newName == employees[i]->GetName())
		{
			return employees[i];
		}
	}
	return 0;
}

RegardEmployees::~RegardEmployees()
{
}
