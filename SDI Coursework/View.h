#pragma once
#include "Employee.h"
#include "Item.h"
#include <vector>

class View
{
public:
	View();
	~View();
	void DisplayMainMenu();
	void DisplayMenuSelectionRequest();
	void DisplayInputRequest();

	void DisplayAllEmployees(vector<Employee*> &allEmployees); // this is a pointer to a vector
	void DisplayEmployee(Employee* newEmployee);
	void DisplayEmployeeFormat();

	void DisplayAllItems(vector<Item*> &allItems);

	int GetUserIntInput();
	string GetUserStringInput();
	// display main menu options
	// functions to get user input - used in system while loop and swtich statement
private:
	int _intInput;
	string _stringInput;
};

