#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class Calc
{
public:
	void basic(std::string mass);
	void inputStack(char val);
	void emptyStack();
	void operation(int h);
private:
	std::stack <char> signs;
	std::stack <std::string> all;
	std::string temporary[10];
	int n = 0;
};