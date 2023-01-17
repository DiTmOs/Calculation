#include "Calc.h"

 void Calc::basic(std::string mass)
{
	double answer;
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
		std::cout << "i:"<< i << std::endl;
		if (mass[i] != '+' && mass[i] != '-' && mass[i] != '/' && mass[i] != '*' && mass[i] != '(' && mass[i] != ')' && mass[i] != '^')
		{
			number += mass[i];
		}
		else
		{
			inputStack(mass[i]);
			if (number != "")
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
	int h = 0;
	for (int i = 0; i < coll; i++)
	{
		if (out[i] != "")
		{
			if (out[i] == "+")
			{
				h = 1;
				operation(h);
			}
			else if (out[i] == "/")
			{
				h = 4;
				operation(h);
			}
			else if (out[i] == "*")
			{
				h = 3;
				operation(h);
			}
			else if (out[i] == "-" && (out[i + 1] == "+" || out[i + 1] == "-" || out[i + 1] == "*" || out[i + 1] == "/" || out[i + 1] == "^"))
			{
				h = 7;
				operation(h);
			}
			else if (out[i] == "-")
			{
				h = 2;
				operation(h);
			}
			else if (out[i] == "^")
			{
				h = 5;
				operation(h);
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
		 else if ((val == '*' || val == '/') && (signs.top() == '*' || signs.top() == '/') || signs.top() == '^')
		 {
			 while (!signs.empty() && signs.top() != '(' && (signs.top() != '-' || signs.top() != '+'))
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
 void Calc::operation(int &h)
 {
	 std::string temporary;
	 double number1, number2;
	 if (!all.empty())
	 {
		 empty(number1, number2, temporary, h);
		 if (h == 1)
		 {
			 answer = number1 + number2;
		 }
		 else if (h == 2)
		 {
			 answer = number1 - number2;
		 }
		 else if (h == 3)
		 {
			 answer = number1 * number2;
		 }
		 else if (h == 4)
		 {
			 answer = number1 / number2;
		 }
		 else if (h == 5)
		 {
			 if(number2 >= 1)
			 answer = pow(number1, number2);
			 else
			 {
				 std::cout << "Error(exponentiation is incorrect)!" << std::endl;
				 exit(1);
			 }
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
 void Calc::empty(double &num1,double &num2,std::string temp, int &h)
 {
	 if (all.size() > 1 && h !=7 )
	 {
		 temp = all.top();
		 all.pop();
		 num2 = stod(temp);
		 temp = all.top();
		 all.pop();
		 num1 = stod(temp);
	 }
	 else if (!all.empty() && (all.size() == 1 || h == 7))
	 {
		 temp = all.top();
		 all.pop();
		 answer = stod(temp);
		 answer *= -1;
		 h = 0;
	 }
 }