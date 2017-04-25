#include "stdafx.h"
#include "SystemManager.h"
#include "View.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"

SystemManager::SystemManager()
{
	_v = new View();
	_fm = new FileManager();
	_ef = new EmployeeFactory();
	_re = new RegardEmployees();

	_isRunning = true;
	_choice = 0;
}

void SystemManager::ParseEmployees()
{
	vector<string> myEmployees; // local vector
	Employee *newEmp = NULL;
	myEmployees = _fm->CreateVectorOfLines("MyEmployees.txt"); // file manager create a vector of lines
	for (vector<string>::iterator it = myEmployees.begin(); it != myEmployees.end(); ++it) 
	{
		newEmp = _ef->CreateEmployee(*it); // Factory creates an employee
		_re->AddEmployee(newEmp); // get employee method to return vector
	}
}
void SystemManager::StartSystem()
{
	ParseEmployees();

	_v->DisplayMainMenu();

	while (_isRunning) // _isRunning initialised to true
	{
		_v->DisplayMenuSelectionRequest();
		int _choice = _v->GetUserInput();
		switch (_choice)
		{
		case 0:
			_v->DisplayAllEmployees(_re->GetAllEmployees());
			break; // loops back to user input
		case 1:
			_v->DisplayInputRequest();
			int searchVal = _v->GetUserInput(); // make search val an _member variable?
			_re->SortByID(_re->GetAllEmployees()); // takes a vector refence
			_v->DisplayEmployee(_re->SearchID(_re->GetAllEmployees(), searchVal));
			break;
		}
	}

}

SystemManager::~SystemManager()
{
}
