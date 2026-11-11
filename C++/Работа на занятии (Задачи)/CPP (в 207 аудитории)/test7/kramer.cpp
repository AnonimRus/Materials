#include <iostream>
#include <fstream>

float det(float a[4][4]);

using namespace std;

void main()
{
	ifstream a_dat("a.dat");
	ifstream b_dat("b.dat");

	float a[4][4];
	float b[4];
	float x[4];

	float w[4][4];

	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			a_dat >> a[i][j];
		}
		b_dat >> b[i];
	}


	float main_det = det(a);
	
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
			for (int k = 1; k < 4; k++)
				w[j][k] = a[j][k];
		
		w[1][i] = b[1];
		w[2][i] = b[2];
		w[3][i] = b[3];

		x[i] = det(w) / main_det;
	}
	cout << "x1 = " << x[1] << ", x2 = " << x[2] << ", x3 = " << x[3] << endl;


	system("pause");
}