/*

a = (ax, ay, az)
b = (bx, by, bz)

c = a x b = (cx, cy, cz)

cx = ay*bz - az*by
cy = az*bx - ax*bz
cz = ax*by - ay*bx

*/

#include <fstream>
using namespace std;

void main()
{
	ofstream file("output.txt");

	int a[3] = {1, 1, 0};
	int b[3] = {0, 0, 1};
	int c[3];

	c[0] = a[1]*b[2] - a[2]*b[1];
	c[1] = a[2]*b[0] - a[0]*b[2];
	c[2] = a[0]*b[1] - a[1]*b[0];

	file << c[0] << " " << c[1] << " " << c[2] << endl;
}