#pragma once
#include "Employee.h"
#include <vector>

class View
{
public:
	View();
	~View();
	void DisplayAllEmployees(vector<Employee*> &allEmployees); // this is a pointer to a vector
	void DisplayEmployee(Employee* newEmployee);
	void DisplayMainMenu();
	void DisplayMenuSelectionRequest();
	void DisplayInputRequest();
	int GetUserInput();
	// display main menu options
	// functions to get user input - used in system while loop and swtich statement
private:
	int _userInput;
};

