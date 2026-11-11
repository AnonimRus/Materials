#include <iostream>
#include <fstream>

using namespace std;

void main ()
{
	char wanted[20];
	char name[10];
	char surname[20];
	int n;

	cout << "input wanted surname: ";
	cin >> wanted;

	ifstream file_in("group.txt");

	int i = 0;
	do
	{
		file_in >> n >> name >> surname;
		cout << name << " " << surname << endl;
	}
	while( strcmp(surname, wanted) != 0  && strcmp(surname, "") != 0);

	system("pause");
}	