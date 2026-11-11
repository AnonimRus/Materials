#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	ifstream file1("text.txt");
	ofstream file2("output.txt");

	int count_letters = 0;
	int count_words = 1;

	char line[80];

	file1.getline( line ,80, '\n');

	cout << line << endl;

	int i = 0;  
	while(line[i] != '\0')
	{
		if ((line[i] == ' ') && (line[i + 1] != ' ') && (line[i + 1] != '\0')) count_words++;
		else if (line[i] != ' ') count_letters++;
		i++;
	}

	file2 << "Count_letters = " << count_letters << endl;
	file2 << "Count_words = " << count_words << endl;

}