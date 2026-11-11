#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void main()
{
	ofstream file("file.dat");
	for (double i = -10.0; i < 11.0; i = i + 1.0)
	{
		double result = exp(-i*i);
		file << i << " " << result << endl;
	}
}
