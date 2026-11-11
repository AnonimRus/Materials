#include <iostream>
#include <fstream>

int det2(float a[3][3]);
int det3(float a[4][4]);

using namespace std;

void main()
{
	ifstream matrix("matrix.dat");
	ofstream output("inverse.dat");

	float a[4][4];
	float A[4][4];

	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
			matrix >> a[i][j];
		}

	int det_matrix = det3(a);
	
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
			float minor[3][3];
			
			int m_i = 1;
			for (int row = 1; row < 4; row++)
			{
				if (row == i)
					continue;
				int m_j = 1;

				for (int col = 1; col < 4; col++)
				{
					if (col == j)
						continue;

					minor[m_i][m_j] = a[row][col];
					m_j++;
				}
				m_i++;
			}

			float val = det2(minor);

			if ((i + j) % 2 == 0)
				A[i][j] = val;
			else
				A[i][j] = -val;
		}

	for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
            output << A[j][i] / det_matrix << " ";
        output << endl;
    }
}