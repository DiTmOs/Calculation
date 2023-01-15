#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class Calc
{
public:
	void basic(std::string mass);//�������� ��� ���������. ���������� �������������� ������  � �������� �������� ������ � ����������� �����������.
	void inputStack(char val);// ������� ������ � ���� signs ����� ��������.
	void emptyStack();//������� �������� �����. ���� ��  �� ����, �� ������� ��� �������� �� ��������� ������ temporary.
	void operation(int h);//������� ���������� ��������.������� �� ����� all ��� �������� � ���������� � ���� ��������.
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
};