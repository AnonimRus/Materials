#include <iostream>
#include <math.h>

using namespace std;

double fun(double x)
{
	return sin(x) - x/2.0;
}

void main ()
{
	//setlocale(LC_ALL, "Russian");
	
	double x1, x2;

	cout << "Input x1, x2: " << endl;
	cin >> x1 >> x2;

	double tol;

	cout << "Input tol: " << endl;
	cin >> tol;

	double dx;
	double x;

	do
	{
		dx = (x2 - x1)/2.0;
		x = x1 + dx;
		if (fun(x) > 0.0)
			x1 = x;
		else
			x2 = x;
	}
	while(dx > tol);

	cout << "x = " << x << ", fun = " << fun(x) << endl;

	system("pause");
}