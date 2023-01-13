#include "Calc.h"

 void Calc::input(std::string mass)
{
	std::string number = "";
	int size,coll(0);
	size = mass.length();
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == '+' || mass[i] == '-' || mass[i] == '/' || mass[i] == '*')
		{
			coll += 1;
		}
	}
	std::string* out = new std::string[coll+(coll-1)];
	coll = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] != '+' && mass[i] != '-' && mass[i] != '/' && mass[i] != '*' && mass[i] != '(' && mass[i] != ')')
		{
			number += mass[i];
		}
		else
		{
			inputStack(mass[i]);
			out[coll] += number;
			coll += 1;
			out[coll] = outSign();
			number = "";
		}
	}
}
