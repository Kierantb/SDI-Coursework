#pragma once
#include "View.h"
#include "FileManager.h"
#include "EmployeeFactory.h"
#include "RegardEmployees.h"
class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void Start();
	void ParseEmployees();
private:
	View* _v;
	FileManager* _fm;
	EmployeeFactory* _ef;
	RegardEmployees* _re; // does this go here?
};

