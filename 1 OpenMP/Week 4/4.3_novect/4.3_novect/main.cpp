#include <iostream>
#include "func.h"


int main()
{
	int n = 100;
	float* a = new float[n];
	float* b = new float[n];
	float* c = new float[n];
	float* d = new float[n];
	float* e = new float[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
		b[i] = 2;
		c[i] = 3;
		d[i] = 4;
		e[i] = 5;
	}
	add_floats(a, b, c, d, e, n);

    return 0;
}