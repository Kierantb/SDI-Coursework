#pragma once
#include "View.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"
#include "ItemFactory.h"
#include "RegardItem.h"
#include "Customer.h"
#include "CustomerFactory.h"
#include "RegardCustomer.h"
#include <vector>
class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void StartSystem(); // single function to initiate system and loop through options
	void ParseEmployees();
	void ParseItems();
	void ParseCustomers();
private:
	View* _v;
	FileManager* _fm;

	Employee* _newEmployee;
	EmployeeFactory* _ef;
	RegardEmployees* _re;

	Item* _newItem;
	ItemFactory* _if;
	RegardItem* _ri;

	Customer* _newCustomer;
	CustomerFactory* _cf;
	RegardCustomer* _rc;

	bool _isRunning;
	int _choice;
	int _intSearchVal;
	string _strSearchVal;
};

