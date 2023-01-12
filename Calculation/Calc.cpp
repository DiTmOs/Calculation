#include "Calc.h"
void input(std::string mass)
{
	std::string perem = NULL;
	int size,coll(1);
	size = mass.length();
	for (int i = 0; i < size; i++)
	{
		if (mass[i] != '+' || mass[i] != '-' || mass[i] != '/' || mass[i] != '*' || mass[i] != '(' || mass[i] != ')')
		{
			coll += 1;
		}
	}
	double* massiv = new double[coll];
	coll = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] != '+' || mass[i] != '-' || mass[i] != '/' || mass[i] != '*' || mass[i] != '(' || mass[i] != ')')
		{
			perem += mass[i];
		}
		else
		{
			massiv[coll] = std::stod(perem);
			coll += 1;
		}
	}
}
