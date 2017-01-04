#include <iostream>
#include <math.h>
#include <float.h>
#include <string>
#include <vector>
#include <sstream>


std::string doubleToString(double number)
{
	std::ostringstream output;
	output << number;
	return output.str();

}

bool isAction(char input);
bool isAlpha(char input);
bool inNum(char input);
bool isFunc(std::string str, int &length);

std::string timesPoly(std::string first, std::string second);

/*The goal of this program is to get all the way into calculus, but there's a problem;
 *	The computer does not understand what a fraction is.
 *	We need a fraction class, but next problem is that we need to accept variables,
 *	and even worse, variables with exponents since x^2 can't be added to 3x 
 *	So, First step = fract class. 
 *	*/
class fract
{
	public:
	fract();
	std::string getNumer();
	std::string getDenom();
	void setNumer(std::string numerator);
	void setDenom(std::string denominator);
	void setVariable(char variable, double value);
	void flip();
	void plus(fract other);
	void minus(fract other);
	void multiply(fract other);
	void divide(fract other);
	
	std::string solve(std::string input);
	

	int isAction(char plusminmultdiv);
	std::string grabNextNum(std::string input, int &lastPos);
	std::string chopSpaces(std::string input);
	void likeTerms();


	void print();
	
		
	private:
	std::string numer;
	std::string denom;
	std::vector <double> variables;
	

};


using namespace std;

string spaceFunction(string input);



int main(int argc, char ** argv)
{
	if(argc > 1)
	{
		cout << argv[1] << endl;
	}

	char var = '+';

	fract bob;
	bob.setNumer("3x^2+3");
	bob.setDenom("12x^2");
	bob.setVariable('x', 3);
	cout << bob.solve(bob.getNumer());
	cout << "\nPrint: " << endl;
	bob.print();
	cout << endl;

	return 0;
}


string spaceFunction(string input)
{
	
}



fract::fract()
{
	for(int i = 0; i < 'z'; i ++)
	{
		variables.push_back(0);
	}
}

string fract::getNumer()
{
	return this->numer;
}

string fract::getDenom()
{
	return this->denom;
}

void fract::setNumer(std::string numerator)
{
	numer = "(";
	numer += numerator;
	numer += ")";
}
void fract::setDenom(std::string denominator)
{
	denom = "(";
	denom += denominator;
	denom += ")";
}

void fract::plus(fract other)
{
	numer = "(" + numer;
	numer = numer + " * ";
	numer = numer + other.denom;
	numer = numer + " + ";
	numer = numer + other.numer;
	numer = numer + " * ";
	numer = numer + denom;
	numer = numer + ")";
	denom = "(" + denom;
	denom = denom + " * ";
	denom = denom + other.denom;
	denom = denom + ")";
}

void fract::minus(fract other)
{
	numer = "(" + numer + " * " + other.denom + " - " + other.numer + " * " + denom + ")";
	denom = "(" + denom + " * " + other.denom + ")";
}

void fract::multiply(fract other)
{
	numer = "(" + numer + " * " + other.numer + ")";
	denom = "(" + denom + " * " + other.denom + ")";
}

void fract::likeTerms()
{
	numer = chopSpaces(numer);
	denom = chopSpaces(denom);
	char signBetween = ' ';
	for(int i = 0; i < numer.length(); i++)
	{
		if(isAlpha(numer[i]))
		{
			
		}
	}
}
string fract::chopSpaces(string input)
{
	string output;
	for(int i = 0; i < input.length(); i ++)
	{
		if(input[i] != ' ')
		{
			output += input[i];
		}
	}
	return output;
}

/*

int fract::isAction(char in)
{
	if(in == '+')
	{
		return 1;
	}
	else if('-')
	{
		return 2;
	}
}

*/

void fract::print()
{
	cout << numer << '/' << denom;
}

void fract::flip()
{
	string holder = numer;
	numer = denom;
	denom = holder;
}


bool isAlpha(char input)
{
	if(input >= 'a' && input <= 'z')
	{
		return true;
	}
	else if(input >= 'A' && input <= 'Z')
	{
		return true;
	}
	return false;
}
/*
string fract::grabNextNum(string input, int &lastPos)
{
	string nextNumber;
	int oldPos = lastPos;
	bool exit = false;
	for(int i = lastPos; i < input.length() && exit == false; i ++)
	{
		if((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
		{
			nextNumber += input[i];
			cout << nextNumber;
		}
		else if( nextNumber == "")
		{
			
		}
		else
		{
			exit = true;
			lastPos += i;
		}
	}
	
	oldPos = oldPos + lastPos - nextNumber.length();
	return (lastPos > oldPos)? input.substr(oldPos, lastPos - oldPos) : "";
}*/



void fract::setVariable(char variable, double value)
{
	variables[variable] = value;
}

bool isAction(char input)
{
	if(input == '+' || input == '-' || input == '*' || input == '/' || input == '^')
	{
		return true;
	}
	return false;
}

bool isNum(char input)
{
	if((input >= '0' && input <= '9') || input == '.')
	{
		return true;
	}
	return false;
}

bool isFunc(string str, int &length)
{
	for(int i = 0; i < str.length(); i ++)
	{
		string temp = str.substr(0, i);
		if(temp == "ln" || temp == "derive" || temp == "times" || temp == "sin" || temp =="cos" || temp == "tan" || temp == "arctan" || temp == "arcsin" || temp == "arccos" || temp == "e" || temp =="pi" || temp == "pie")
		{
			length = temp.length();
			return true;
		}
	}
	return false;
}


double activate(char action, double first, double second)
{
	double solution = 0;
	if(action == '+')
	{
		return first + second;
	}
	else if(action == '-')
	{
		return first - second;
	}
	else if(action == '/')
	{
		return first / second;
	}
	else if(action == '*')
	{
		return first * second;
	}
	else if(action == '^')
	{
		solution = 1;
		for(int i = 0; i < second; i ++)
		{
			solution = solution * first;
		}
		return solution;
	}
}

/*ISSUES: PEMDAS is not accurate when functions come into play. I can't simply remove all parenthesis, */
string fract::solve(string input)
{
	bool isNegative = false;
	string temp = "";
	string front = "";
	string back = "";
	double first = DBL_MAX;
	double second = DBL_MAX;
	double solution = 1;
	// PEMDAS; parens, Exponents, Mult, Div, Add, Subtract	
	
	// keep going deeper into parenthesis until deepest is found.
	size_t posOpen = 0;
	size_t posClose = 0;
	posOpen = numer.find('(', posOpen);
	posClose = numer.find(')', posOpen);
	
	
	if(posOpen != string::npos)
	{
		if(posOpen > 0)
		{
			front = input.substr(0, posOpen - 1);
		}

		temp = input.substr(posOpen + 1, posClose - 1 - posOpen);
		cout << temp;
//		temp = this->solve(temp); //I thought this was the right place for recursion, wrong?
		if(temp.find('(') != string::npos)
		{
			 solve(temp);// solve for deeper parens
		}

		if(posClose != string::npos)
		{
			back = input.substr(posClose,  0);
		}
		// cout << front << " " << back;
		input = front;
		input += temp;
		input += back;
		cout << input;
		
	}	
	if(posOpen == string::npos)
	{
		return "deepest.";
	}
	if(input[0] == '-')
	{
		isNegative = true;
	}

// Exponents - have to take into account possibility of functions or variables and lack there-of
/*int funcLength = 0;
	for(int i = 0; i < input.length(); i ++)
	{
		
		if(isAlpha(input[i]) && !(isFunc(input.substr(i,string::npos), funcLength)))
		{
			cout << '|' <<  input[i] << " is a variable" << endl;
		}
		else if(isFunc(input.substr(i,string::npos), funcLength))
		{
			cout << '|' << input.substr(i, string::npos) << " is a function" << endl;
			i += funcLength - 1;
			
		}
		else if(isNum(input[i]))
		{
			int startPos = i;
			while(isNum(input[i]))
			{
				i++;
			}
			i --;
			int endPos = i;
			cout << input[i];
		}
	}
*/
	//exponent attempt 2 - for now we ignore unctions like ln and sin/cos/tan etc.
	size_t expPos = input.find('^');
	if(isAlpha(input[expPos -1]))
	{	
		first = variables[input[expPos - 1]];
		cout << '-' <<input[expPos -1] << "=" <<first << '-';
	}
	else if(isNum(input[expPos -1]))
	{
		for(int k = 1; isNum(input[expPos - k]); k --)
		{
			startPos = expPos - 
		}
	}
	
	//PEMDAS - last working right here;
	
	
	return "solved";	
}





