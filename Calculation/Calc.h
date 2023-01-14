#include <iostream>
#include <string>
#include <stack>

class Calc
{
public:
	void input(std::string mass);
	void inputStack(char val);
	void emptyStack();
	std::string outSign();
private:
	std::stack <char> signs;
	std::string temporary[10];
	int n = 0,m = 0;
};