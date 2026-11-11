#include <iostream>
#include <fstream>

using namespace std;

void main()
{

ifstream file1("text.txt");
int count=0;


char* line = new char[80];


file1.getline( line ,80, '\n');

cout << line << endl;


char x;
cout << " input symbol to count" << endl;
cin >> x;


while(*line != '\0')
{

  if( *line == x )count++;
  ++line;
}

cout << " count=" << count << endl;


system("pause");
}