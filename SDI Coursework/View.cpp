#include "stdafx.h"
#include "View.h"
#include <iostream>
#include <vector>

View::View()
{
	_intInput = 0;
	_stringInput = "";
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
	// type: ...
	cout << "ID: " << newEmployee->GetID() << endl;
	cout << "Name: " << newEmployee->GetName() << endl;
	cout << "Email: " << newEmployee->GetEmail() << endl;
	cout << "Monthly Wage: " << newEmployee->GetMonthlyPay() << endl;
}
void View::DisplayAllItems(vector<Item*> &allItems)
{
	cout << "\nResult:\n" << endl;
	for (size_t i = 0; i < allItems.size(); i++)
	{
		cout << allItems[i]->GetType() << ": " << allItems[i]->GetName() << endl;
	}
}
void View::DisplayMainMenu()
{
	cout << "\t\t PC Builder Application\n\n" << endl;
	cout << "0. - Display all employees" << endl;
	cout << "1. - Search for Employee ID" << endl;
	cout << "2. - Search for Employee Name" << endl;
	cout << "3. - Add Employee" << endl;
	cout << "4. - Delete Employee by ID" << endl;
	cout << "5. - Display all items" << endl;
}
void View::DisplayEmployeeFormat()
{
	cout << "Enter in the following format:\n Type ID Name Email Wages monthly Hours" << endl;
}
void View::DisplayMenuSelectionRequest()
{
	cout << "\nPlease enter an option from the main menu: ";
}
void View::DisplayInputRequest()
{
	cout << "\nPlease enter your input: ";
}
int View::GetUserIntInput()
{
	cin >> _intInput; // can do error checking in this function e.g. turn string into ints and check that they all fully ints between like 1-9
	return _intInput;
}
string View::GetUserStringInput()
{
	cin.ignore(256, '\n'); // prevent getline from taking \n from users enter
	getline(cin, _stringInput);
	cout << "You entered: " << _stringInput << endl;
	return _stringInput;
}
View::~View()
{
}
