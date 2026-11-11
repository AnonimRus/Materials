#include <iostream>
#include <cmath>

using namespace std;

double func (double x)
{
	return sin(x) - x/2
}

void main ()
{
	double x = 0f;
	double y = func(x);
	
	for (int i = 0; i < 4; i++)
	{
		while True:
		{
			x = x + (1/(pow(10, i))) * sign(y);
			y = func(x);

			if y < 0:
				break;
		}
	}

	system("pause");
}