
class point
{
	public:
	point(double x, double y);
	point();
	double x;
	double y;

};

point::point()
{
	x = 0;
	y = 0;
}

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
}

class line
{
	public:
	line(double startx, double starty, double endx, double endy);
	line(point start, point end);
	double intersect(line otherLine);
	double slope();
	bool isInBounds(double xValue);

	private:
	point first;
	point last;
		
};

line::line(double startx, double starty, double endx, double endy)
{
	first.x = startx;
	first.y = starty;
	last.x = endx;
	last.y = endy;
}
line::line(point start, point end)
{
	first = start;
	last = end;
}

// returns (change in y) / (change in x)
double line::slope()
{
	return ((last.y-first.y)/(last.x-first.x));
}

// returns the x position in which an intersection would take place
double line::intersect(line ol)
{
	double slope1 = this->slope();
	double slope2 = ol.slope();
	return (((((-1)*(slope1)*first.x))+(first.y) - ol.first.y + (slope2 * ol.first.x))/(slope2-slope1));
}

bool line::isInBounds(double x)
{
	if(x > first.x && x - first.x < last.x)
	{
		return true;
	} 
	return false;
}

/* EXAMPLE */
#include <iostream>
using namespace std;

int main()
{

	line left(1, 5, 38,34);
	line right(5,5, 12, 87);
	double intersection = right.intersect(left);
	cout << "First slope = " << left.slope() << endl;
	cout << "Second slope = " << right.slope() << endl;
	cout << "These lines would intersect at x=" << intersection << " which is " << endl;
	if(left.isInBounds(intersection))
	{
		cout << "in the range/domain given" << endl;

	}
	else
	{
		cout << "not in the range/domain given" << endl;
	}
	cout << endl;

}
/* END EXAMPLE */


