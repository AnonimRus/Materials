/*

V = |(a, b, c)|

*/

#include <fstream>
using namespace std;

int det3(int a[3][3])
{
	return a[0][0] * (a[1][1]*a[2][2] - a[2][1]*a[1][2]) - a[1][0] * (a[0][1]*a[2][2] - a[2][1]*a[0][2]) + a[2][0] * (a[0][1]*a[1][2] - a[1][1]*a[0][2]);
}

void main()
{
	ofstream file("output.txt");

	int a[3] = {1, 1, 0};
	int b[3] = {0, 0, 1};
	int c[3] = {1, 0, 0};
	int matrix[3][3];
	int det_matrix;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == 0)
			{
				matrix[i][j] = a[j];
			}
			else if (i == 1)
			{
				matrix[i][j] = b[j];
			}
			else if (i == 2)
			{
				matrix[i][j] = c[j];
			}

	det_matrix = det3(matrix);
	file << det_matrix << endl;
}