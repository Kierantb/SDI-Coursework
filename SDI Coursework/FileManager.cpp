#include "stdafx.h"
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include "Employee.h"

FileManager::FileManager()
{
}
vector<string> FileManager::CreateVectorOfLines(string newFileName)
{
	vector<string> lineInfo;

	ifstream inFile(newFileName); // e.g. foo.txt
	string line;
	while (getline(inFile, line))
	{
		lineInfo.push_back(line);
	}
	inFile.close();
	return lineInfo; // returns vector of lines used by factories
}
void FileManager::OverwriteFile(string newFileName, vector<Employee*>& currentEmployees) // potentially make bool and pass result to view?
{
	ofstream outFile(newFileName);

	size_t length = currentEmployees.size();
	for (size_t i = 0; i < length; i++)
	{
		outFile << currentEmployees[i]->GetType() << " " << currentEmployees[i]->GetID() << " " << currentEmployees[i]->GetName() << " "
			<< currentEmployees[i]->GetEmail() << " " << currentEmployees[i]->GetWages() << " " << currentEmployees[i]->GetHoursWorked() << "\n";
	}

	outFile.close();
}
FileManager::~FileManager()
{
}
