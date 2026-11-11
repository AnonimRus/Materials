#include <fstream>
#include <iostream>

using namespace std;

void main()
{
	ifstream matrix1("matrix1.dat");
	ifstream matrix2("matrix2.dat");

	int a[3][3];
	int b[3][3];
	int c[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			matrix1 >> a[i][j];
			matrix2 >> b[i][j];
		}	

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum = sum + a[i][k] * b[k][j];		
			}
			c[i][j] = sum;
		}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
		

	system("pause");
}