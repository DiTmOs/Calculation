#include "Calc.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Calc test;
	//std::string prob = "(3*5.2+3)/(2.2-1.5)+6";
	std::string prob;
	std::cout << "¬ведите пример: ";
	std::cin >> prob;
	test.basic(prob);
}