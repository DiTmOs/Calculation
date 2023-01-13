#include <iostream>
#include <string>
#include <stack>

class Calc
{
public:
	void input(std::string mass);
	void inputStack(char val);
	std::string outSign();
private:
	std::stack <std::string> values;
	std::string temporary;
};