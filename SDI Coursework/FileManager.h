#pragma once
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;

class FileManager
{
public:
	FileManager();
	~FileManager();
	vector<string> CreateVectorOfLines(string newFileName);
	void OverwriteEmployeeFile(string newFileName, vector<Employee*>& currentEmployees);
};