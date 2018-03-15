#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	const long int n = 40000000;
	double* a = new double[n];
	double* b = new double[n];
	double* c = new double[n];
	for (long int i = 0; i < n; i++)
	{
		a[i] = (double)rand() / RAND_MAX;
		b[i] = (double)rand() / RAND_MAX;
	}
	double time = omp_get_wtime();
#pragma omp parallel shared(a,b,c) num_threads(4)
#pragma omp for schedule(dynamic, 10000)
	for (long int i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}
	cout << "c[100]=" << c[100] << endl;
	cout << "Time parallel = " << (omp_get_wtime() - time) << endl;

	for (long int i = 0; i < n; i++)
		c[i] = 0;

	time = omp_get_wtime();

	for (long int i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}

	cout << "c[100]=" << c[100] << endl;
	cout << "Time = " << (omp_get_wtime() - time) << endl;

	delete[] a;
	delete[] b;
	delete[] c;
}
