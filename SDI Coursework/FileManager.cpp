#include "stdafx.h"
#include "FileManager.h"
#include <fstream>

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
	return lineInfo; // returns vector of lines used by factories
}

FileManager::~FileManager()
{
}
