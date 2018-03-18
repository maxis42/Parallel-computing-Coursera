#include "GaussSeidel.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Boundary values for u function
double G(double x, double y) {
	if (x == 0) return 1 - 2 * y;
	if (x == 1) return -1 + 2 * y;
	if (y == 0) return 1 - 2 * x;
	if (y == 1) return -1 + 2 * x;
}



// Initial values for f function
double F(double x, double y) {
	return 2.2;
}



// Output result matrix
// Show only 11x11 array with equally spaced rows and columns
void UOutput(double** u, int N) {
	cout << fixed << setprecision(3);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++)
			cout << setw(7) << u[i * (N + 1) / 10][j * (N + 1) / 10];
		cout << endl;
	}
}



// Allocate memory for array NxN
double** new_arr(int N) {
	double** f = new double*[N];

	for (int i = 0; i < N; i++)
		f[i] = new double[N];

	return f;
}



// Deallocate memory for array NxN
int delete_arr(double** arr,int N) {
	for (int i = 0; i < N; i++)
		delete[] arr[i];
	
	delete[] arr;
	return 0;
}



// Initialize f and boundary u values
void Init(double **u, double **f, int N) {
	// N - number of points across each axis (square grid NxN)
	// side length == 1
	// h - step across axis
	double h = 1.0 / (N + 1);


	// initialize f array (right part of the Puasson equation)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			f[i][j] = F((i + 1) * h, (j + 1) * h);


	// initialize u array (target function in the left part of the Puasson equation)
	// initialize u[i=1,N][j=1,N]
	const int U_INIT_VAL = 0.2;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			u[i][j] = U_INIT_VAL;

		// initialize u[i=1,N][0], u[i=1,N][N+1] (first and last columns)
		u[i][0] = G(i * h, 0);
		u[i][N + 1] = G(i * h, (N + 1) * h);
	}
	// initialize u[0][j], u[N+1][j] (first and last rows)
	for (int j = 0; j < N + 2; j++) {
		u[0][j] = G(0, j * h);
		u[N + 1][j] = G((N + 1) * h, j * h);
	}
}