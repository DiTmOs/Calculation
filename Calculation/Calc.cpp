#include "Calc.h"

 void Calc::basic(std::string mass)
{
	 double answer;
	std::string number = "";
	int size,coll(1);
	size = mass.length();
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == '+' || mass[i] == '-' || mass[i] == '/' || mass[i] == '*')
		{
			coll += 1;
		}
	}
	coll = coll * 2;
	std::string* out = new std::string[coll];
	coll = 0;
	for (int i = 0; i <= size; i++)
	{
		if (mass[i] != '+' && mass[i] != '-' && mass[i] != '/' && mass[i] != '*' && mass[i] != '(' && mass[i] != ')')
		{
			number += mass[i];
		}
		else
		{
			std::cout << "i:" << i << std::endl;
			inputStack(mass[i]);
			if (number != "")
			{
				out[coll] += number;
				std::cout << "out:" << out[coll] << std::endl;
				coll += 1;
			}
			if (n != 0)
			{
				for (int g = 0; g < n; g++)
				{
					out[coll] += temporary[g];
					std::cout << "out:" << out[coll] << std::endl;
					++coll;
				}
				n = 0;
			}
			number = "";
		}
	}
	out[coll] = number;
	number = "";
	++coll;
	emptyStack();
	if (n != 0)
	{
		for (int g = 0; g < n; g++)
		{
			out[coll] += temporary[g];
			++coll;
		}
		n = 0;
	}
	for (int i = 0; i < coll; i++)
	{
		std::cout << "out["<<i <<"]: " << out[i] << std::endl;
	}
	for (int i = 0; i < coll; i++)
	{
		if (out[i] == "+" )
		{
			operation(1);
		}
		else if (out[i] == "/")
		{
			operation(4);
		}
		else if (out[i] == "*")
		{
			operation(3);
		}
		else if (out[i] == "-")
		{
			operation(2);
		}
		else
		{
			all.push(out[i]);
		}
	}
	answer = stod(all.top());
	all.pop();
	std::cout << "Answer:" << answer << std::endl;
	delete[] out;
}
 void Calc::inputStack(char val)
 {
	 if (!signs.empty())
	 {
		 if ((val == '+' || val == '-')&& (signs.top() != '(' ))
		 {
			 temporary[n] = signs.top();
			 signs.pop();
			 signs.push(val);
			 ++n;
		 }
		 else if ((val == '*' || val == '/') && (signs.top() == '*' || signs.top() == '/'))
		 {
			 temporary[n] = signs.top();
			 signs.pop();
			 signs.push(val);
			 ++n;
		 }
		 else if (val == ')')
		 {
			 while (signs.top() != '(' && !signs.empty())
			 {
				 temporary[n] = signs.top();
				 ++n;
				 signs.pop();
			 }
			 signs.pop();
		 }
		 else if (val == '(')
		 {
			 signs.push(val);
		 }
		 else
		 {
			 signs.push(val);
		 }
	 }
	 else
	 {
		 signs.push(val);
	 }
 }
 void Calc::emptyStack()
 {
	 while (!signs.empty())
	 {
		 temporary[n] = signs.top();
		 ++n;
		 signs.pop();
	 }
 }
 void Calc::operation(int h)
 {
	 std::string temporary;
	 double number1, number2,number;
	 if (!all.empty())
	 {
		 temporary = all.top();
		 all.pop();
		 number2 = stod(temporary);
		 temporary = all.top();
		 all.pop();
		 number1 = stod(temporary);
		 if (h == 1)
		 {
			 number = number1 + number2;
		 }
		 else if (h == 2)
		 {
			 number = number1 - number2;
		 }
		 else if (h == 3)
		 {
			 number = number1 * number2;
		 }
		 else if (h == 4)
		 {
			 number = number1 / number2;
		 }
		 temporary = std::to_string(number);
		 all.push(temporary);
	 }
 }