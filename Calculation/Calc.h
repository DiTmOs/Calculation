#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>

class Calc
{
public:
	void Calculation(std::string mass);//�������� ��� ���������. ���������� �������������� ������  � �������� �������� ������ � ����������� �����������.
	void inputStack(char val);// ������� ������ � ���� signs ����� ��������.
	void removingElements();//������� �������� �����. ���� ��  �� ����, �� ������� ��� �������� �� ��������� ������ temporary.
	void GetValue(double &num1,double &num2);
	void operation(char sign);//������� ���������� ��������.������� �� ����� all ��� �������� � ���������� � ���� ��������.
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