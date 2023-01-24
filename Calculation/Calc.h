#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>

class Calc
{
public:
	void basic(std::string mass);//�������� ��� ���������. ���������� �������������� ������  � �������� �������� ������ � ����������� �����������.
	void inputStack(char val);// ������� ������ � ���� signs ����� ��������.
	void emptyStack();//������� �������� �����. ���� ��  �� ����, �� ������� ��� �������� �� ��������� ������ temporary.
	void empty(double &num1,double &num2, std::string temp);
	void operation(char sign);//������� ���������� ��������.������� �� ����� all ��� �������� � ���������� � ���� ��������.
	int numberOFdigits(std::string massiv,int size);
	bool isOperator(char element,bool type);
	bool CheckingExpression(std::string expression);
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
	double answer;
};