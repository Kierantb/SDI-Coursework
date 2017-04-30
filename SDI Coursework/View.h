#pragma once
#include "Employee.h"
#include "Item.h"
#include "PC.h"
#include "Customer.h"
#include <vector>

class View
{
public:
	View();
	~View();
	void DisplayMainMenu();
	void DisplayMenuSelectionRequest();
	void DisplayInputRequest();
	void DisplayIDRequest();
	void DisplayEmployeeFormat();

	void DisplayAllEmployees(vector<Employee*> &allEmployees);
	void DisplayEmployee(Employee* newEmployee);
	void DisplayAllItems(vector<Item*> &allItems);
	void DisplayItemName(vector<Item*> &allItems);
	void DisplayAllPCsPrice(vector<PC*> &allPCs);
	void DisplayPCBuild(vector<PC*> &allPCs);
	void DisplayPCWithinPriceRange(double low, double high, vector<PC*> &allPCs);
	void DisplayPCBuildAtIndex(vector<PC*> &allPCs, int index);
	void DisplayAllCustomerNames(vector<Customer*> &allCustomers);

	void PrintReceipt(vector<Item*> &customersPurchasedItems);

	int GetUserIntInput();
	string GetUserStringInput();

private:
	int _intInput;
	string _stringInput;
};

