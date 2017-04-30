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
	_cf = new CustomerFactory();
	_rc = new RegardCustomer();

	_newEmployee = NULL;
	_newItem = NULL;
	_newCustomer = NULL;

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
void SystemManager::ParseCustomers()
{
	vector<string> myCustomers;
	myCustomers = _fm->CreateVectorOfLines("MyCustomers.txt");
	for (vector<string>::iterator it = myCustomers.begin(); it != myCustomers.end(); ++it)
	{
		_newCustomer = _cf->CreateCustomer(*it); // Factory creates an employee
		_rc->AddCustomer(_newCustomer); // get employee method to return vector
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
	ParseCustomers();
	ParseItems();
	_ri->SortItemType(); // create function for these actions
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
			_re->SortByID(_re->GetAllEmployees()); // takes a vector reference
			_v->DisplayEmployee(_re->SearchID(_re->GetAllEmployees(), _intSearchVal)); // could be made clearer
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
			// ITEM STUFF BELOW
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
			// CUSTOMER STUFF BELOW
		case 9: // display customer names
			_v->DisplayAllCustomerNames(_rc->GetAllCustomers());
			break;
		case 10: // find customer
			_v->DisplayInputRequest(); // customer will have their ID with ID number
			_intSearchVal = _v->GetUserIntInput(); // user enters the customers ID
			_newCustomer = _rc->GetCustomerByID(_intSearchVal); // now we know who wants to add item to basket below
			break;
		case 11: // add item to basket
			_v->DisplayInputRequest();
			_v->DisplayIDRequest();
			_intSearchVal = _v->GetUserIntInput();
			_ri->SortItemByID(_ri->GetAllItems()); // sort items by ID
			_newItem = _ri->SearchItemByID(_ri->GetAllItems(), _intSearchVal); // find item by id
			_newCustomer->AddItemToBasket(_newItem); // add item to current customers basket
			break;
		case 12: // create membership
			_newCustomer->SetMembership("True"); // versatile
			break;
		case 13: // buy items
			//_rc->SendItems(_newCustomer->GetBasket());
			_v->PrintReceipt(_newCustomer->GetBasket());
			_ri->RemoveBasketFromItems(_newCustomer->GetBasket()); // needs implementing
			//_rc->SendEmail();
			break;
		}
	}
}

SystemManager::~SystemManager()
{
}
