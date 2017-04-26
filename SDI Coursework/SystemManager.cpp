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
	_newEmployee = NULL;
	_intSearchVal = 0;
	_strSearchVal = "";
}

void SystemManager::ParseEmployees()
{
	vector<string> myEmployees; // local vector - make member variable?
	myEmployees = _fm->CreateVectorOfLines("EmployeeRecords.txt"); // file manager creates a vector of lines
	for (vector<string>::iterator it = myEmployees.begin(); it != myEmployees.end(); ++it) 
	{
		_newEmployee = _ef->CreateEmployee(*it); // Factory creates an employee
		_re->AddEmployee(_newEmployee); // get employee method to return vector
	}
}
void SystemManager::StartSystem()
{
	ParseEmployees();

	_v->DisplayMainMenu();
	// implement change employee type function e.g. change part time to full time/ change wage & Pay priority
	while (_isRunning) // _isRunning initialised to true
	{
		_v->DisplayMenuSelectionRequest();
		_choice = _v->GetUserIntInput();
		switch (_choice)
		{
		case 0: // display all employee names
			_v->DisplayAllEmployees(_re->GetAllEmployees());
			break;
		case 1: // search by ID
			_v->DisplayInputRequest();
			_intSearchVal = _v->GetUserIntInput(); // make search val an _member variable?
			_re->SortByID(_re->GetAllEmployees()); // takes a vector refence
			_v->DisplayEmployee(_re->SearchID(_re->GetAllEmployees(), _intSearchVal));
			break;
		case 2: // search by name
			_v->DisplayInputRequest();
			_strSearchVal = _v->GetUserStringInput();
			_v->DisplayEmployee(_re->SearchName(_re->GetAllEmployees(), _strSearchVal));
			break;
		case 3: // add employee
			_v->DisplayEmployeeFormat(); // shoes user what format to enter string in
			_v->DisplayInputRequest();
			_strSearchVal = _v->GetUserStringInput(); // not a search value...
			_newEmployee = _ef->CreateEmployee(_strSearchVal); // Factory creates an employee
			_re->AddEmployee(_newEmployee); // get employee method to return vector
			_fm->OverwriteFile("EmployeeRecords.txt", _re->GetAllEmployees());
			break;
		case 4: // delete employee
			_v->DisplayInputRequest();
			_intSearchVal = _v->GetUserIntInput();
			_re->SortByID(_re->GetAllEmployees());
			_newEmployee = _re->SearchID(_re->GetAllEmployees(), _intSearchVal);
			_re->DeleteEmployee(_newEmployee);
			_fm->OverwriteFile("EmployeeRecords.txt", _re->GetAllEmployees());
			break;
		}
	}

}

SystemManager::~SystemManager()
{
}
