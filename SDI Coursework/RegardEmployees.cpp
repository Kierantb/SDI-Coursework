#include "stdafx.h"
#include "RegardEmployees.h"
#include <iostream>
#include <vector>
using namespace std;


RegardEmployees::RegardEmployees()
{
}
void RegardEmployees::AddEmployee(Employee * newEmployee)
{
	_currentEmployees.push_back(newEmployee);
}
vector<Employee*>& RegardEmployees::GetAllEmployees() // maybe make const, const
{
	return _currentEmployees; // returns reference
}
void RegardEmployees::SortByID(vector<Employee*> &unsortedEmployees) // can be void?
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
	return nullptr; // result might not exist - find better way to handle this
}
RegardEmployees::~RegardEmployees()
{
}
