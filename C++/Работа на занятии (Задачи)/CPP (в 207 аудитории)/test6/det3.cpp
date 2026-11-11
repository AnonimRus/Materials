int det3(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33)
{
	int res = a11*a22*a33 + a21*a32*a13 + a12*a23*a31 - a31*a22*a13 - a21*a12*a33 - a32*a23*a11;
	return res;
}