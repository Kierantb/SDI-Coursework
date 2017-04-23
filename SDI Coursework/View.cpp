#include "stdafx.h"
#include "View.h"
#include <iostream>

View::View()
{
}
void View::DisplayEmployees(Employee *allEmployees, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << allEmployees[i].GetName() << endl;
	}
}

View::~View()
{
}
