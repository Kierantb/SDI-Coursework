#pragma once

#include<string>
using namespace std;

class Item
{
public:
	Item();
	~Item();
private:
	int _id;
	string _name;
	double _buyPrice;
	double _sellPrice;
};

