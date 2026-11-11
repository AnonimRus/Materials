#include <iostream>
#include <fstream>

using namespace std;

void main ()
{
	char name[10];
	char surname[20];
	int n;

	ofstream file_out("group.txt");

	cout << "input number of participants: ";
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cout << "person ¹" << i << " input name: ";
		cin >> name;

		cout << "input surname: ";
		cin >> surname;

		file_out << i << " " << name << " " << surname << endl;
	}
	system("pause");
}