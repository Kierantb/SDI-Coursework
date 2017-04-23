#pragma once
#include <string>
#include <vector>
using namespace std;

class FileManager
{
public:
	FileManager();
	~FileManager();
	vector<string> CreateVectorOfLines(string newFileName);
};