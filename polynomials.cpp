
#include <string>
#include <vector>

double getDoubleFromString(std::string, int & pos);

class variable
{
	public:
	variable(std::string polynomial);
	void addFunction(std::string polynomial);
	double findX(double x);
	void parseFunction();
	
	private:
	double xvar;
	std::string function;
	std::vector <double> numbers;
	std::vector <std::string> actions;
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
