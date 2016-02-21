#include <iostream>
#include <cmath>

class term
{
	public:
	term(double multiplier, double variable, double exponent);
	term();
	void reset(double multiplier, double variable, double exponent);
	void setMult(double multiplier);
	void setExp(double exponent);
	void setVar(double variable);
	double calculate();
	double getMult();
	double getExp();
	double getVar();
	
	private:
	double mult, var, exp;
	
};


