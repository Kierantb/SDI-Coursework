#include "stdafx.h"
#include "View.h"
#include <iostream>
#include <vector>

View::View()
{
	_userInput = 0;
}
void View::DisplayAllEmployees(vector<Employee*> &allEmployees)
{
	cout << "\nResult:\n" << endl;
	for (size_t i = 0; i < allEmployees.size(); i++)
	{
		cout << allEmployees[i]->GetName() << endl;
	}
}
void View::DisplayEmployee(Employee* newEmployee)
{
	cout << "\nResult:\n" << endl;
	cout << newEmployee->GetName() << endl;
}

void View::DisplayMainMenu()
{
	cout << "\t\t PC Builder Application\n\n" << endl;
	cout << "0. - Display all employees" << endl;
	cout << "1. - Search Employee ID" << endl;
}
void View::DisplayMenuSelectionRequest()
{
	cout << "\nPlease enter an option from the main menu: ";
}
void View::DisplayInputRequest()
{
	cout << "\nPlease enter your input: ";
}
int View::GetUserInput()
{
	cin >> _userInput; // can do error checking in this function e.g. turn string into ints and check that they all fully ints between like 1-9
	return _userInput;
}
View::~View()
{
}
