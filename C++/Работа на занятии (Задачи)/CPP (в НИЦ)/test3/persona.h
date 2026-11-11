#include <iostream>
using namespace std;

class Persona
{
	public:
		char Name[10];
		char FName[15];
		char Surname[20];
		int Age;
		char City[10];
		void Print();
};

void Persona::Print()
{
	cout << Name << endl;
}