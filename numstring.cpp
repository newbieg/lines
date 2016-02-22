/* de[rovated begore implemented;
 *
 * I started this class as a way to grab numbers out of a string.
 * Turns out, that is implemented in c++11, std::stod(string, position, base);
 * just be sure to compile  with g++ -std=c++11 filename.cpp
 *
 * I'll just keep this file around as a reminder if I happen across it again.
 *
 *
 *
#include <string>

class numstring
{
	public:
	numstring(std::string number);
	numstring();
	void setString(std::string number);
	std::string getNextNumber(int &position);
	std::string getNextString(int &position);
	std::string getContents();
	
	private:
	std::string input;
	
};

numstring::numstring(std::string number)
{
	input = number;
}

numstring::numstring()
{
	input = "";
}

void numstring::setString(std::string number)
{
	input = number;
}

std::string numstring::getNextNumber(int &position)
{
	bool isNum = true;
	for(int i = position; i < input.size() && isNum; i ++)
	{
		if(input[i] == '-')
		{

		}
	}
	return "not implemented yet";
}

std::string numstring::getNextString(int &position)
{
	return "not implemented yet";
}

std::string numstring::getContents()
{
	return input;
}


/* Example: /
#include <iostream>

using namespace std;
int main()
{
	string input = "-34";
	int num = stoi(input, );
	
}
/**/
