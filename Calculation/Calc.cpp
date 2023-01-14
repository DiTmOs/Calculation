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
			while (m != 0)
			{
				out[coll] += outSign();
				coll += 1;
			}
			number = "";
		}
	}
	emptyStack();
	while (m != 0)
	{
		out[coll] += outSign();
		coll += 1;
		signs.pop();
	}
	delete[] out;
}
 void Calc::inputStack(char val)
 {
	 if ((val == '+' || val == '-') && ( signs.top() == '-' || signs.top() == '*' || signs.top() == '/' || signs.top() == '+'))
	 {
		 temporary[n] = signs.top();
		 signs.pop();
		 signs.push(val);
		 n += 1;
		 m = 1;
	 }
	 else if ((val == '*' || val == '/') && ( signs.top() == '*' || signs.top() == '/'))
	 {
		 temporary[n] = signs.top();
		 signs.pop();
		 signs.push(val);
		 n += 1;
		 m = 1;
	 }
	 else if (val == ')')
	 {
		 while (signs.top() != '(' && !signs.empty())
		 {
			 temporary[n] = signs.top();
			 n += 1;
			 signs.pop();
		 }
		 signs.pop();
		 m = 1;
	 }
	 else if (val == '(')
	 {
		 signs.push(val);
	 }
 }
 std::string Calc::outSign()
 {
	 std::string temporary;
	 if (n != 0)
	 {
		 temporary = temporary[n];
		 n -= 1;
	 }
	 else
	 {
		 temporary = temporary[n];
		 m = 0;
	 }
	 return temporary;
 }
 void Calc::emptyStack()
 {
	 while (!signs.empty())
	 {
		 temporary[n] = signs.top();
		 n += 1;
		 signs.pop();
	 }
	 m = 1;
 }
