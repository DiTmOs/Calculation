#include "Calc.h"
int main()
{
	//setlocale(LC_ALL, "Russian");
	Calc test;
	std::string prob = "(3*5.2+3)/(2.2-1.5)+6";
	/*std::string prob;
	std::cout << "Enter an example (we enclose the entire expression in brackets, we always mark the unary minus with brackets on both sides:(-number)): ";
	std::cin >> prob;*/
	if (!test.CheckingExpression(prob))
		test.Calculation(prob);
	else
	{
		std::cout << "Error(Expression have a letter)!";
		exit(1);
	}
}