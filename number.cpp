/*	I'm just thinking of what a number is, and I want to create all the
 *	theoretical bits that I can, so here's the list;
 *	* Possitive and negative
 *	* numerator and denominator
 *	* imaginary and real
 *	* has an exponent (usually of one)
 *
 * 	Current issue; math as applied to a string.
 * */

#include <string>
#include <iostream>

using namespace std;

class number
{
	public:
	number();
	number(string, string, string);
	void print();

	private:
	bool lessThanZero;
	bool imagined;
	string expt;
	string denom;
	string numerat;
	string imaginedPart;
	
};

number::number()
{
	lessThanZero = false;
	imagined = true;
	expt = "1";
	denom = "1";
	numerat = "0";
	
}

number::number(string numerator, string denominator = "1", string exponent = "1")
{
	if(numerator[0] == '-')
	{
		lessThanZero = true;
		numerator = numerator.substr(1, numerator.length());
	}
	numerat = numerator;
	denom = denominator;
	expt = exponent;
}

void number::print()
{
	cout << "(" << numerat << "/" << denom << ")" << " to the " << expt << " degree";
	if(imagined)
	{
		cout << " and with imaginary concerns.";
	}

}


int main()
{
	number bob;
	bob.print();
	return 0;
}
