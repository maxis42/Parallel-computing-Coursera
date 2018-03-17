#include <iostream>
#include "func.h"

using namespace std;
int main()
{
	int n = 16;
	float* a = new float[n];
	float* b = new float[n];
	float* c = new float[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
		b[i] = i;
		c[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		c[i] = add_floats(a[i], b[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << "c[" << i << "]=" << c[i] << endl;
	}

	return 0;
}