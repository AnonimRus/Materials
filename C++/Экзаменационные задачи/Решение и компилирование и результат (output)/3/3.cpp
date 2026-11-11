/*

Перевод в другую систему счисления (10 -> 2, 10 -> 8, 10 -> 16)

*/

#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	ofstream file("output.txt");

	int num, i, num_;
	cout << "Input your number: ";
	cin >> num;

	file << "Decimal: " << num << endl;

	char bin[32], oct[11], hex[8];

	i = 0;
	num_ = num;
	char binChars[] = "01";
	while (num_ > 0)
	{
		bin[i] = binChars[num_ % 2];
		num_ = num_ / 2;
		i++;
	}
	file << "Binary: ";
	for (int j = i - 1; j >= 0; j--)
		file << bin[j];
	file << endl;


	i = 0;
	num_ = num;
	char octChars[] = "01234567";
	while (num_ > 0)
	{
		oct[i] = octChars[num_ % 8];
		num_ = num_ / 8;
		i++;
	}
	file << "Octal: ";
	for (int j = i - 1; j >= 0; j--)
		file << oct[j];
	file << endl;


	i = 0;
	num_ = num;
	char hexChars[] = "0123456789ABCDEF";
	while (num_ > 0)
	{
		hex[i] = hexChars[num_ % 16];
		num_ = num_ / 16;
		i++;
	}
	file << "Hexadecimal: ";
	for (int j = i - 1; j >= 0; j--)
		file << hex[j];
	file << endl;

}