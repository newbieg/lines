/* depricated before implemented;
 *
 * I started this class as a way to grab numbers out of a string.
 * Turns out, that is implemented in c++11, std::stod(string, position, base);
 * just be sure to compile  with g++ -std=c++11 filename.cpp
 *
 * I'll just keep this file around as a reminder if I happen across it again.
 *
 *
 *

/* Example: */
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string input = "-34";
	double num = stod(input, 0);
	cout << num << endl;
	
}
/**/
