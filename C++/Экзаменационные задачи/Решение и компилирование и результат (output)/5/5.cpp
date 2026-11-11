/*

Определитель матрицы 4x4

*/

#include <iostream>
#include <fstream>
using namespace std;

int det3(int a[3][3])
{
	return a[0][0] * (a[1][1]*a[2][2] - a[2][1]*a[1][2]) - a[1][0] * (a[0][1]*a[2][2] - a[2][1]*a[0][2]) + a[2][0] * (a[0][1]*a[1][2] - a[1][1]*a[0][2]);
}

int det4(int a[4][4])
{
	int num;
	int det = 0;
	int matr[3][3];
	for (int i = 0; i < 4; i++)
	{
		num = a[0][i];

		int row = 0;
		for (int j = 1; j < 4; j++)
		{
			int col = 0;
			for (int k = 0; k < 4; k++)
			{
				if (k != i)
				{
					matr[row][col] = a[j][k];
					col++;
				}
			}
			row++;
		}
		if (i % 2 == 0) det += num * det3(matr);
		else det -= num * det3(matr);
	}
	return det;
}

void main()
{
	ifstream file1("input.txt");
	ofstream file2("output.txt");

	int matrix[4][4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			file1 >> matrix[i][j];
		}

	file2 << det4(matrix);

}