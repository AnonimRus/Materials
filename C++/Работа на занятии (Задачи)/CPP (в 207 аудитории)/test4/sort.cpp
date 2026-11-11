#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	ifstream array("array.txt");

	int arr[10];
	int save;

	for (int i = 0; i < 10; i++)
		array >> arr[i];
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				save = arr[j];

				arr[j] = arr[j + 1];
				arr[j + 1] = save;
			}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	system("pause");
}