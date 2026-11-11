#include <iostream>
#include <fstream>
using namespace std;

//--------------------MINOR------------------------------------

void minor(int i,int j, int **a, int **b, int n )
{

int k1=-1;
int m1;

for(int k=0; k<n; k++)
{
  if(k==i)continue;
  k1++;
  m1=-1;   
  for(int m=0; m<n; m++)
  {
    if(m==j)continue;
    m1++;
    b[k1][m1]=a[k][m];         
  }
}

}

//--------------------SIGN-------------------------------------
int sig(int i)
{
  int res;
  if(i%2 == 0) res=1;
  else res=-1;
   
  return res;
}

//------------------------DET-------------------------------
int det(int **a, int n )
{
int **b;
b = new int*[n];
for(int i=0; i<n; i++)
b[i]=new int[n];

int res;

if(n <= 2) res=a[0][0]*a[1][1]-a[1][0]*a[0][1];
else
{
  res=0;
  for(int j=0; j<n; j++) 
  {
    minor(0,j,a,b,n);
    res= res+sig(j)*a[0][j]*det(b,n-1);
  }
}

return res;
}



//--------------------MAIN-------------------------------------
void main()
{
int **a;

ifstream matrix("matrix.dat");
int n;

//----------------INPUT MATRIX------------------------------
matrix >> n;
 
a = new int*[n];

for(int i=0; i<n; i++)
{
  a[i] = new int[n];
  for(int j=0; j<n; j++)
    matrix >> a[i][j];
}
//--------------------TEST OUTPUT---------------------------
cout << n << endl;
for(int i=0; i<n; i++)
{
  for(int j=0; j<n; j++)
    cout << a[i][j] <<"  ";
  cout << endl;
}

int result=det(a,n);
cout << " result=" << result << endl;

system("pause");
}