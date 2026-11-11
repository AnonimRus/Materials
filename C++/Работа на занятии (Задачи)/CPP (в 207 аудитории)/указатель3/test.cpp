#include <iostream>
#include <fstream>

using namespace std;

void main()
{


int count1=0;
int count2=0;
int count3=0;

char x1;
cout << " input symbol to count #1" << endl;
cin >> x1;

char x2;
cout << " input symbol to count #2" << endl;
cin >> x2;

char x3;
cout << " input symbol to count #3" << endl;
cin >> x3;

ifstream file1("text.txt");

char line[80];

int i;

while( file1.getline( line ,80, '\n') ) 
{
  cout << line << endl; 

  i=0;  
  while(line[i] != '\0')
  {

    if( line[i] == x1 )count1++;
    if( line[i] == x2 )count2++;
    if( line[i] == x3 )count3++;
    i++;
   }

}


cout << x1 << " count=" << count1 << endl;
cout << x2 << " count=" << count2 << endl;
cout << x3 << " count=" << count3 << endl;

system("pause");
}