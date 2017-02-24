// PART 1;
// Create some data for x that can be used in a line-of-best-fit program
// As such, the data will need some off-set either by adding a sine function,
// or just a rand pull.

// PART 2;
// Analyze this data to determine slope and initial y-intercept

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

const double DATAPOINTS = 10000;
const double SLOPE = -0.53;
const double STARTHEIGHT = 10;
const double DELTAX = 150;

class point
{
	public:
	point(double _x, double _y);
	
	double x, y;
};


class lineOfBestFit
{
	public:
	lineOfBestFit(std::vector <point> info);
	double getSlope();
	double getSlope(size_t startPos, size_t length);
	double getYIntercept();

	void printDataSet();
	void printLine();

	private:
	std::vector <point> info;
	double slope;
	double b; // yIntercept
	double sumX;
	double sumY;
	double sumXX;
	double sumXY;
	double N;



};

using namespace std;

point::point(double _x, double _y)
{
	x = _x;
	y = _y;
}



double functionOfX(double input)
{
	double value = 0;
	value = (SLOPE * input) + STARTHEIGHT; // y = mx + b
	return value;

}

void printVector(vector <point> info)
{
	for(int i = 0; i < info.size(); i ++)
	{
		cout << info[i].x << "," << info[i].y << " ";
	}
} 

lineOfBestFit::lineOfBestFit(vector <point> data)
{
	info = data;
	N = info.size();
	sumX = 0;
	sumY = 0;
	sumXY = 0;
	sumXX = 0;
	for(int i = 0; i < N; i ++)
	{
		sumX += info[i].x;
		sumY += info[i].y;
		sumXY += info[i].x * info[i].y;
		sumXX += info[i].x * info[i].x;
	}
}


double lineOfBestFit::getSlope()
{
	slope = ((sumX * sumY) - (N * sumXY))/((sumX * sumX)-(N * (sumXX)));
	return slope;

}
double lineOfBestFit::getSlope(size_t startPos, size_t length)
{
	size_t end = startPos + length;
	double tempSumX = 0, tempSumY = 0, tempSumXY, tempSumXX = 0;

	for(size_t i = startPos; i < length; i ++)
	{
		tempSumX += info[i].x;
		tempSumXX += info[i].x * info[i].x;
		tempSumY += info[i].y;
		tempSumXY += info[i].x * info[i].y;
	}
	return ((tempSumX * tempSumY) - (length * tempSumXY))/((tempSumX * tempSumX)-(length * (tempSumXX)));
}

double lineOfBestFit::getYIntercept()
{
	return (sumY - slope * sumX)/N;
}

int main()
{
	vector <point> data;
	// Data Creation
	double x = 0;
	double y = 0;
	for(int i = 0; i < DATAPOINTS; i ++)
	{
		x += DELTAX;
		y = functionOfX(x);
		y += sin(10 * x);
		point newPoint(x, y);
		data.push_back(newPoint);
	}

//	printVector(data);

	// Data Analysis
	lineOfBestFit bob(data);
	cout << "Guess of slope = ";
	cout << bob.getSlope() << endl;
	cout << "Y intercept = " << bob.getYIntercept() << endl;

	cout << endl << "Note, using double, this program will fail if a number over " << sqrt(pow(2, sizeof(double)*8)) << " is encountered" << endl;


}
