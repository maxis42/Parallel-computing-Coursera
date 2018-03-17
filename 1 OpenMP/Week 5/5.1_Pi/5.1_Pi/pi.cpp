#include <stdio.h>
#include <time.h>
#include "fx.h"

#define N 4000000000

double f(double x);

int main()
{
	double sum, pi, x, h;
	clock_t start, stop;
	long long int i;

	h = (double)1.0 / (double)N;
	sum = 0.0;

	start = clock();
	for (i = 0; i<N; i++) {
		x = h*(i - 0.5);
		sum = sum + f(x);
	}
	stop = clock();

	// print value of pi to be sure multiplication is correct
	pi = h*sum;
	printf("    pi is approximately : %f \n", pi);
	// print elapsed time
	printf("Elapsed time = %lf seconds\n", ((double)(stop - start)) / CLOCKS_PER_SEC);
	return 0;
}