#include <iostream>
#include <cmath>

/**
class term
{
	public:
	term(double multiplier, double variable, double exponent);
	term();
	void reset(double multiplier, double variable, double exponent);
	void setMult(double multiplier);
	void setExp(double exponent);
	void setVar(double variable);
	double getMult();
	double getExp();
	double getVar();
	double calculate();
	
	private:
	double mult, var, exp;
	
};
/**/

term::term(double multiplier, double variable, double exponent)
{
	mult = multiplier;
	var = variable;
	exp = exponent;
}

term::term()
{
	mult = 1;
	var = 0;
	exp = 1;
}
void term::reset(double multiplier, double variable, double exponent)
{
	mult = multiplier;
	var = variable;
	exp = exponent;
}

void term::setMult(double multiplier)
{
	mult = multiplier;
}

void term::setExp(double exponent)
{
	exp = exponent;
}

void term::setVar(double variable)
{
	var = variable;
}

double term::calculate()
{
	double answer = std::pow(var, exp);
	answer *= mult;
	return answer;
}

double term::getMult()
{
	return mult;
}

double term::getExp()
{
	return exp;
}

double term::getVar()
{
	return var;
}


/* Example: 3x3^3, 3^2, 2x3 /
using namespace std;
int main(int argc, char ** argv)
{
	term bob(3, 3, 3);
	cout << bob.calculate() << endl;

	bob.reset(1, 3, 2);
	cout << bob.calculate() << endl;
	
	bob.reset(2, 3, 1);
	cout << bob.calculate() << endl;

}
/**/
