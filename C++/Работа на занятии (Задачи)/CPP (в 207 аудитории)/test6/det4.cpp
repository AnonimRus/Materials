#include <iostream>
#include <fstream>

int det3(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33);

using namespace std;

void main()
{
	ifstream matrix("Matrix.dat");

	int a[5][5];

	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
			matrix >> a[i][j];
	
	int test3 = det3(a[1][1], a[1][2], a[1][3], a[2][1], a[2][2], a[2][3], a[3][1], a[3][2], a[3][3]);
	cout << test3 << endl;

	int A11 = det3(a[2][2], a[2][3], a[2][4], a[3][2], a[3][3], a[3][4], a[4][2], a[4][3], a[4][4]);
	int A12 = - det3(a[2][1], a[2][3], a[2][4], a[3][1], a[3][3], a[3][4], a[4][1], a[4][3], a[4][4]);
	int A13 = det3(a[2][1], a[2][2], a[2][4], a[3][1], a[3][2], a[3][4], a[4][1], a[4][2], a[4][4]);
	int A14 = - det3(a[2][1], a[2][2], a[2][3], a[3][1], a[3][2], a[3][3], a[4][1], a[4][2], a[4][3]);

	int det = a[1][1] * A11 + a[1][2] * A12 + a[1][3] * A13 + a[1][4] * A14;
	cout << det << endl;
	

	system("pause");
}