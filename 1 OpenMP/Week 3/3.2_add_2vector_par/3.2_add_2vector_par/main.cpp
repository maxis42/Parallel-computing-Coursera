#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	const long int n = 40000000;
	double* a =new double[n];
	double* b =new double[n];
	double* c =new double[n];
	for (long int i = 0; i < n; i++)
	{
		a[i] = (double)rand() / RAND_MAX;
		b[i] = (double)rand() / RAND_MAX;
	}
	double time = omp_get_wtime();
	for (int j = 0; j < 100; j++)
	{
#pragma omp parallel shared(a,b,c) 
#pragma omp for 
		for (long int i = 0; i < n; i++)
		{
			c[i] = a[i] + b[i];
		}
	}
	cout << "c[100]=" << c[100] << endl;
	cout << "Time = " << (omp_get_wtime() - time) / 100 << endl;
	delete[] a;
	delete[] b;
	delete[] c;
}
