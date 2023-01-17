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
	void empty(double &num1,double &num2, std::string temp, int &h);
	void operation(int &h);//������� ���������� ��������.������� �� ����� all ��� �������� � ���������� � ���� ��������.
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
	double answer;
};