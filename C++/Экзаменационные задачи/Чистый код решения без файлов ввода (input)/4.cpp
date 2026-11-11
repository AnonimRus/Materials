/*

Умножение матриц

*/

#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	ifstream file1("input1.txt");
	ifstream file2("input2.txt");
	ofstream file3("output.txt");

	int matrix1[4][4];
	int matrix2[4][4];
	int result_matrix[4][4];
	int element;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			file1 >> matrix1[i][j];
			file2 >> matrix2[i][j];
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			element = 0;
			for (int k = 0; k < 4; k++)
			{
				element += matrix1[i][k]*matrix2[k][j];
			}
			result_matrix[i][j] = element;
		}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			file3 << result_matrix[i][j] << " ";
		}
		file3 << endl;
	}
}