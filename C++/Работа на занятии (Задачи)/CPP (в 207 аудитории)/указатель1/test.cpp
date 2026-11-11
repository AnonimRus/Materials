#include <iostream>
#include <fstream>

using namespace std;

void main()
{

char* line=" Text for work \n";

char x;

cout << " input symbol for counting" << endl;
cin >> x;

cout << line << endl;

int count=0;


while(*line != '\n')
{
 
  if( *line == x )count++;
  ++line;

}

cout << " count=" << count << endl;


system("pause");
}