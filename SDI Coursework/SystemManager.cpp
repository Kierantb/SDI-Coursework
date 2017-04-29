#include "stdafx.h"
#include "SystemManager.h"
#include "View.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"

#include <iostream>
using namespace std;

SystemManager::SystemManager()
{
	_v = new View();
	_fm = new FileManager();
	_ef = new EmployeeFactory();
	_re = new RegardEmployees();
	_if = new ItemFactory();
	_ri = new RegardItem();

	_newEmployee = NULL;
	_newItem = NULL;

	_isRunning = true;
	_choice = 0;
	_intSearchVal = 0;
	_strSearchVal = "";
}

void SystemManager::ParseEmployees()
{
	vector<string> myEmployees; // local vector - make member variable?
	myEmployees = _fm->CreateVectorOfLines("MyEmployees.txt"); // file manager creates a vector of lines
	for (vector<string>::iterator it = myEmployees.begin(); it != myEmployees.end(); ++it) 
	{
		_newEmployee = _ef->CreateEmployee(*it); // Factory creates an employee
		_re->AddEmployee(_newEmployee); // get employee method to return vector
	}
}
void SystemManager::ParseItems()
{
	vector<string> myItems;
	myItems = _fm->CreateVectorOfLines("MyItems.txt");
	for (vector<string>::iterator it = myItems.begin(); it != myItems.end(); ++it)
	{
		_newItem = _if->CreateItem(*it); 
		_ri->AddItem(_newItem);
	}
}
void SystemManager::StartSystem()
{
	ParseEmployees();
	ParseItems();
	_ri->SortItemType();
	_ri->BuildAllPCs();

	int va2 = 0;
	// implement change employee type function e.g. change part time to full time/ change wage & Pay priority
	while (_isRunning) // _isRunning initialised to true
	{
		_v->DisplayMainMenu();
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
			_fm->OverwriteEmployeeFile("MyEmployees.txt", _re->GetAllEmployees());
			break;
		case 4: // delete employee
			_v->DisplayInputRequest();
			_intSearchVal = _v->GetUserIntInput();
			_re->SortByID(_re->GetAllEmployees());
			_newEmployee = _re->SearchID(_re->GetAllEmployees(), _intSearchVal);
			_re->DeleteEmployee(_newEmployee);
			_fm->OverwriteEmployeeFile("MyEmployees.txt", _re->GetAllEmployees()); // needs fixing
			break;
		case 5: // display all item names
			_v->DisplayAllItems(_ri->GetAllItems());
			break;
		case 6: // display all builds
			_v->DisplayPCBuild(_ri->GetAllPCs());
			break;
		case 7: // display PC index within price range
			_v->DisplayInputRequest();
			_intSearchVal = _v->GetUserIntInput();
			_v->DisplayInputRequest();
			va2 = _v->GetUserIntInput();
			_v->DisplayPCWithinPriceRange(_intSearchVal, va2, _ri->GetAllPCs()); // low, high, vector (within range)
			break;
		case 8: // display a pc build at certain index
			_v->DisplayInputRequest();
			_intSearchVal = _v->GetUserIntInput();
			_v->DisplayPCBuildAtIndex(_ri->GetAllPCs(), _intSearchVal);
			break;
		case 9: //customer stuff
			break;
		}
	}
}

SystemManager::~SystemManager()
{
}
