#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void main()
{
	double sum = 0;
	for (double x = -10.0; x < 10.1; x = x + 0.1)
	{
		sum = sum + exp(-x*x) * 0.1;
	}
	cout << sum << endl << sqrt(3.141592) << endl;
	system("pause");
}
