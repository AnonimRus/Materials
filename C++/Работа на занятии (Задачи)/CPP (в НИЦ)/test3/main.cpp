#include "persona.h"
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	Persona student[20];
	ifstream myfile("spisok.txt");

	int i = 0;
	while (myfile >> student[i].Name >> student[i].FName >> student[i].Surname >> student[i].Age >> student[i].City)
	{
		student[i].Print();
		i++;
	}

	system("pause");
}