#include <iostream>
#include <random>

using namespace std;

void main ()
{
	float xmax = 3.1415;
	float ymax = 1.0;

	int n = 0;
	int a;
	cout << "Number of points: ";
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		float wx = float(rand()%100) / 100;
		float x = wx*xmax;
		float wy = float(rand()%100) / 100;
		float y = wy*ymax;

		if (y < sin(x))n++;
	}

	float ratio = float(n) / a;
	float res = (xmax * ymax) * ratio;
	cout << res << endl;

	system("pause");
}