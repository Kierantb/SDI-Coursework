#pragma once
#include<string>
using namespace std;

class Item
{
public:
	Item();
	~Item();
	void SetType(string newType);
	void SetID(string newID);
	void SetName(string newName);
	void SetBuyPrice(string newBuyPrice);
	void SetSellPrice(string newSellPrice);

	string GetType();
	string GetName();
	double GetBuyPrice();
	double GetSellPrice();
	int GetID();
private:
	string _type;
	int _id;
	string _name;
	double _buyPrice;
	double _sellPrice;
};

