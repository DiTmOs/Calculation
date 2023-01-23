#include "Calc.h"

 void Calc::basic(std::string mass)
{
	double answer, temp;
	int point(0);
	std::string number = "";
	int size,coll(1);
	size = mass.length();
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == '+' || mass[i] == '-' || mass[i] == '/' || mass[i] == '*' || mass[i] == '^')
		{
			coll += 1;
		}
	}
	coll = coll * 2;
	std::string* out = new std::string[coll];
	coll = 0;
	for (int i = 0; i <= size; i++)
	{
		if (mass[i] != '+' && mass[i] != '-' && mass[i] != '/' && mass[i] != '*' && mass[i] != '(' && mass[i] != ')' && mass[i] != '^')
		{
			number += mass[i];
		}
		else
		{
			if (mass[i] == '(')
				point = 1;
			if (mass[i] == '-' && point == 1)
				point = 2;
			if (number != "" && point == 2)
			{
				temp = stod(number);
				temp = temp * (-1);
				number = std::to_string(temp);
				out[coll] += number;
				++coll;
				point = 0;
			}
			else if(number != "")
			{
				out[coll] += number;
				++coll;
			}
			if (n != 0)
			{
				for (int g = 0; g < n; g++)
				{
					out[coll] += temporary[g];
					++coll;
				}
				n = 0;
			}
			if (point != 2)
				inputStack(mass[i]);
			number = "";
		}
	}
	/*std::cout << number << std::endl;
	if (number != "")
	{
		out[coll] += number;
		++coll;
	}*/
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
		if (out[i] != "")
		{
			if (out[i] == "+" || out[i] == "-" || out[i] == "^" || out[i] == "*" || out[i] == "/")
			{
				operation(out[i]);
			}
			else
			{
				all.push(out[i]);
			}
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
			 while (!signs.empty() && signs.top() != '(')
			 {
				 temporary[n] = signs.top();
				 signs.pop();
				 ++n;
			 }
			 signs.push(val);
		 }
		 else if ((val == '*' || val == '/') && (signs.top() == '*' || signs.top() == '/' || signs.top() == '^'))
		 {
			 while (!signs.empty() && signs.top() != '(' && signs.top() != '-' && signs.top() != '+')
			 {
				 temporary[n] = signs.top();
				 signs.pop();
				 ++n;
			 }
			 signs.push(val);
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
		 else if (val == '^' && signs.top() == '^')
		 {
			 while (!signs.empty() && signs.top() == '^')
			 {
				 temporary[n++] = signs.top();
				 signs.pop();
			 }
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
 void Calc::operation(std::string sign)
 {
	 std::string temporary;
	 double number1, number2;
	 if (!all.empty())
	 {
		 empty(number1, number2, temporary);
		 /*switch (sign)
		 {
		 case sign == "+":
			 answer = number1 + number2;
			 break;
		 default:
			 break;
		 }*/
		 if (sign == "+")
		 {
			 answer = number1 + number2;
		 }
		 else if (sign == "-")
		 {
			 answer = number1 - number2;
		 }
		 else if (sign == "*")
		 {
			 answer = number1 * number2;
		 }
		 else if (sign == "/")
		 {
			 answer = number1 / number2;
		 }
		 else if (sign == "^")
		 {
			 answer = pow(number1, number2);
		 }
		 temporary = std::to_string(answer);
		 all.push(temporary);
	 }
	 else
	 {
		 std::cout << "Error(empty stack!)" << std::endl;
		 exit(1);
	 }
 }
 void Calc::empty(double &num1,double &num2,std::string temp)
 {
	 if (all.size() > 1)
	 {
		 temp = all.top();
		 all.pop();
		 num2 = stod(temp);
		 temp = all.top();
		 all.pop();
		 num1 = stod(temp);
	 }
	 else 
	 {
		 std::cout << "Error(There are less than 2 elements in the stack)!" << std::endl;
		 exit(1);
	 }
 }