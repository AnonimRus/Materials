#include <iostream>
#include <random>

using namespace std;

void main ()
{
	int x;
	for (int i = 0; i < 10; i++)
	{
		x = rand();
		cout << x << endl;
	}
	
	system("pause");
}