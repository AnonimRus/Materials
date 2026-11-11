#include <iostream>

using namespace std;

int factorial (int x)
{
	if (x <= 1)
		return 1;
	else
		return x * factorial(x - 1);
}

void main ()
{
	int x;
	cin >> x;
	cout << x << "! = " << factorial(x) << endl;
	system("pause");
}