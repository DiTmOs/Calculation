#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>

class Calc
{
public:
	void Calculation(std::string mass);//Основной код программы. Происходит преобразование строки  в обратную польскую запись с последующим вычислением.
	void inputStack(char val);// Функция заноса в стек signs знака операции.
	void removingElements();//Функция проверки стека. Если он  не пуст, то выводит все элементы во временный массив temporary.
	void GetValue(double &num1,double &num2);
	void operation(char sign);//Функция выполнения операции.Достает из стека all два элемента и производит с ними операцию.
	int numberOFdigits(const std::string &massiv,int size);
	bool isOperator(char element);
	bool CheckingExpression(std::string expression);
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
	double answer;
};