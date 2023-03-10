#include "Calc.h"
#include <vector>
#include <cctype>

 void Calc::Calculation(std::string mass)
{
	double answer, temp;
	int point(0);
	std::string number = "";
	int size,coll;
	size = mass.length();
	coll = numberOFdigits(mass, size);
	coll = coll * 2;
	std::vector<std::string> out(coll);
	coll = 0;
	for (int i = 0; i <= size; i++)
	{
		if (!isOperator(mass[i]) && mass[i] != '(' && mass[i] != ')')
		{
			number += mass[i];
		}
		else
		{
			if (mass[i] == '-' && mass[i - 1] == '(')
				point = 2;
			else
				point = 0;
			if (point != 2)
				inputStack(mass[i]);
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
			number.clear();
		}
	}
	if (number != "")
	{
		out[coll] += number;
		++coll;
	}
	removingElements();
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
			if (isOperator(out[i][0]))
			{
				operation(out[i][0]);
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
 void Calc::removingElements()
 {
	 while (!signs.empty())
	 {
		 temporary[n] = signs.top();
		 ++n;
		 signs.pop();
	 }
 }
 void Calc::operation(char sign)
 {
	 double number1, number2;
	 if (!all.empty())
	 {
		 GetValue(number1, number2);
		 switch (sign)
		 {
			case '+':
				 answer = number1 + number2;
				 break;
			case '-':
				 answer = number1 - number2;
				 break;
			case '*':
				 answer = number1 * number2;
				 break;
			case '/':
				 answer = number1 / number2;
				 break;
			case '^':
				 answer = pow(number1, number2);
				 break;
		 }
		 all.push(std::to_string(answer));
	 }
	 else
	 {
		 std::cout << "Error(empty stack!)" << std::endl;
		 exit(1);
	 }
 }
 void Calc::GetValue(double &num1,double &num2)
 {
	 if (all.size() > 1)
	 {
		 num2 = stod(all.top());
		 all.pop();
		 num1 = stod(all.top());
		 all.pop();
	 }
	 else 
	 {
		 std::cout << "Error(There are less than 2 elements in the stack)!" << std::endl;
		 exit(1);
	 }
 }
 int Calc::numberOFdigits(const std::string &massiv, int size)
 {
	 int temp(0);
	 for (int i = 0; i < size; i++)
	 {
		 if (massiv[i] == '+' || massiv[i] == '*' || massiv[i] == '/' || massiv[i] == '^')
		 {
			 temp++;
		 }
		 else if (massiv[i] == '-' && massiv[i - 1] != '(')
		 {
			 temp++;
		 }
		 
	 }
	 temp++;
	 return temp;
 }
 bool Calc::isOperator(char element)
 {
		 switch (element)
		 {
		 case '+':
			 return true;
			 break;
		 case '-':
			 return true;
			 break;
		 case '*':
			 return true;
			 break;
		 case '/':
			 return true;
			 break;
		 case '^':
			 return true;
			 break;
		 default:
			 return false;
			 break;
		 }
 }
 bool Calc::CheckingExpression(std::string expression)
 {
	 int size = expression.length();
	 for (int i = 0; i < size; i++)
	 {
		 if (std::isalpha(expression[i]))
			 return true;
	 }
	 return false;
 }