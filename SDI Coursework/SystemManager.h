#pragma once
#include "View.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"
#include <vector>
class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void StartSystem(); // single function to initiate system and loop through options
	void ParseEmployees();
	
private:
	View* _v;
	FileManager* _fm;
	EmployeeFactory* _ef;
	RegardEmployees* _re;
	vector <Employee *> employees;

	bool _isRunning;
	int _choice;
};

