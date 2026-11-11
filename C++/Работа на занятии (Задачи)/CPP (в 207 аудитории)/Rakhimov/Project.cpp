#include <fstream>
#include <iostream>

using namespace std;

void main()
{
	ifstream list("file.dat");

	int non_sort[15];
	int sort[15];

	for (int i = 0; i < 15; i++)
		list >> non_sort[i];
	
	for (int i = 0; i < 15; i++)
		cout << non_sort[i] << " ";
	cout << endl;

	system("pause");
}