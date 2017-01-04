#include <iostream>
#include <vector>
#include <string>

class poly2{};

class poly
{
	public:
	poly();
	poly(double n, double d, double e);
	void setNum(poly &in);
	void setDen(poly &in);
	void setExp(poly &in);
	poly getNum();
	poly getDen();
	poly getExp();
	double toDouble();
	double calcVal(double X);

	void print();
	
	private:
	poly num(), den(), exp();
	bool stop;
	double numerator, denominator, exponent, x;
};

using namespace std;

poly::poly()
{
	numerator = 1;
	denominator = 1;
	exponent = 0;
	x = 1;
	stop = true;
}

poly::poly(double n, double d, double e)
{
	numerator = n;
	denominator = d;
	exponent = e;
	x = 1;
	stop = true;
}

void poly::setNum(poly &in)
{
	num = in;
	stop = false;
}

void poly::setDen(poly &in)
{
	den = in;
	stop = false;
}

void poly::setExp(poly &in)
{
	exp = in;
	stop = false;
}

double poly::calcVal(double X)
{
	double value = 0;
	double e = 0;
	double n = 0;
	double d = 0;

	if(stop)
	{
		value = (numerator / denominator) * (X^exponent);
	}
	else
	{	
		value = (num.calcVal() / den.calcVal()) * (X^exp.calcVal());
	}
	
	return value;
}

void poly::print()
{
	
}


int main()
{
	poly anne;
	anne.setNum(3);
	anne.setExp(2);
	cout << anne.calcVal(3) << endl;
	
	return 0;

}





