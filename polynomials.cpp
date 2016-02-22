
#include <string>
#include <vector>
#include "term.cpp"

double getDoubleFromString(std::string, int & pos);

class variable
{
	public:
	variable(std::string polynomial);
	void addFunction(std::string polynomial);
	double solveFor(double x);
	void parseFunction();
	
	private:
	double xvar;
	std::string function;
	std::vector <term> numbers;
	std::vector <std::string> actions;
	int position;
};

variable::variable(std::string poly)
{
	function = poly;
}

void variable::addFunction(std::string poly)
{
	function = poly;
}

void variable::parseFunction()
{
	
}

double variable::findX(double x)
{

	return 0;
}




double getDoubleFromString(std::string input, int & pos)
{

	return 0;
}



#include <iostream>
using namespace std;

int main()
{


}
