#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>

class Calc
{
public:
	void basic(std::string mass);//Основной код программы. Происходит преобразование строки  в обратную польскую запись с последующим вычислением.
	void inputStack(char val);// Функция заноса в стек signs знака операции.
	void emptyStack();//Функция проверки стека. Если он  не пуст, то выводит все элементы во временный массив temporary.
	void empty(double &num1,double &num2, std::string temp, int &h);
	void operation(int &h);//Функция выполнения операции.Достает из стека all два элемента и производит с ними операцию.
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
	double answer;
};