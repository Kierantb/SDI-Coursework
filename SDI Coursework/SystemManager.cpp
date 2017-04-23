#include "stdafx.h"
#include "SystemManager.h"


SystemManager::SystemManager()
{
}

void SystemManager::ParseEmployees()
{
	vector<string> myEmployees;
	myEmployees = _fm->CreateVectorOfLines("MyEmployees.txt");
	for (vector<string>::iterator it = myEmployees.begin(); it != myEmployees.end(); ++it) 
	{
		//cout << *it << endl;
		Employee *newEmp = _ef->CreateEmployee(*it); // it works but doesnt return employee properly
		_re->AddEmployee(newEmp);
		//regard employee in systemManager or Factory?
	}

}
SystemManager::~SystemManager()
{
}
