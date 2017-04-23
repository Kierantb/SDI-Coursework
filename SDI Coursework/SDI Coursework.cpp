// SDI Coursework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"
#include <iostream>
using namespace std;
// MODEL
// VIEW
// CONTROLLER

int _tmain(int argc, _TCHAR* argv[])
{
	// TESTING
	FileManager fm;
	EmployeeFactory ef;
	RegardEmployees rg;

	vector<string> myEmployees;

	myEmployees = fm.CreateVectorOfLines("MyEmployees.txt");

	for (vector<string>::iterator it = myEmployees.begin(); it != myEmployees.end(); ++it) {
		/* std::cout << *it; ... */
		cout << *it << endl;

		//Employee *newEmp = ef.CreateEmployee(*it); // it works but doesnt return employee properly

		//rg.AddEmployee(newEmp); // newEmp is memory location
	}
	//rg.PrintEmployees();

	// why isnt employee returning properly?
	// do i have an instance of regard employee in employee factory?
	// how do I get the controller to work?

	cin.get();
	cin.get();
	return 0;
}

