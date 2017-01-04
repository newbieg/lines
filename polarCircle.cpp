#include <iostream>
#include <cmath>

class pcircle
{
	public:
	pcircle(double x, double y, double radius);
	void setPnt(double x, double y);
	bool ptInCircle(double x, double y);
	bool ptOnBoundary(double x, double y);
	double dFM();

	private:
	double origin_x, origin_y, point_x, point_y, rad;
};



using namespace std;

// Define your circle's middle cooridinates, and its radius (1/2 width)
pcircle::pcircle(double x, double y, double radius)
{
	origin_x = x;
	origin_y = y;
	rad = radius;
}

// is the point int the circle
bool pcircle::ptInCircle(double x, double y)
{
	setPnt(x, y);
	if(sqrt((point_x*point_x)+(point_y*point_y)) < rad)
	{
		return true;
	}
	return false;
}

// is the point on the boundary/circumference
bool pcircle::ptOnBoundary(double x, double y)
{
	setPnt(x, y);
	if(sqrt((point_x*point_x)+(point_y*point_y)) == (rad * rad))
	{
		return true;
	}
	return false;
}

void pcircle::setPnt(double x, double y)
{
	point_x = x - origin_x;
	point_y = y - origin_y;
}

double pcircle::dFM()
{
	return sqrt((point_x*point_x)+(point_y*point_y));
}


int main(int argc, char ** argv)
{
	pcircle bobby(32, 95, 12);
	cout << true << " If is in circle: " << bobby.ptInCircle(12, 93) << endl;
	cout << "Dist from circle center = " << bobby.dFM() << endl;
}
