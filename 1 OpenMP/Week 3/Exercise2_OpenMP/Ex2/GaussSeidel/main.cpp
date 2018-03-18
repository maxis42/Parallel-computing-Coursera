//------------------------------------------------------------
// Partial differential equations sover by Gauss–Seidel method
//------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <omp.h>
#include "submit.h"
#include "GaussSeidel.h"
#include "windows.h"
using namespace std;

int main(int argc, char **argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
		
	double **u=NULL, **f=NULL;
	double **u_ser=NULL, **f_ser=NULL;
	double **u_par = NULL, **f_par = NULL;
	
	int N = 600; // N - number of points across each axis (square grid NxN)
	double eps = 0.0001; // Calculation tolerance
	int iter_cnt(0); // Iterations counter
	double tt;

	
	// Sequential algorithm
	tt = omp_get_wtime();

	f_ser = new_arr(N); // f memory allocation
	u_ser = new_arr(N + 2); // u memory allocation
	Init(u_ser, f_ser, N); // f and u initialization

	cout << "Calculating by Gauss–Seidel method (sequential solver)..." << endl;
	iter_cnt = Calc_seq(u_ser, f_ser, N, eps);

	tt = omp_get_wtime() - tt;

	cout << "Serial time = " << tt << " Num of iterations = " << iter_cnt << endl;

	// Output result matrix
	// Show only 11x11 array with equally spaced rows and columns
	cout << "Result of calculation" << endl;
	UOutput(u_ser, N);
	cout << endl;

	// Parallel algorithm
	tt = omp_get_wtime();

	f_par = new_arr(N); // f memory allocation
	u_par = new_arr(N + 2); // u memory allocation
	Init(u_par, f_par, N); // f and u initialization

	cout << "Calculating by Gauss–Seidel method (parallel solver)..." << endl;
	iter_cnt = Calc_par_block(u_par, f_par, N, eps);

	tt = omp_get_wtime() - tt;

	cout << "Parallel time = " << tt << " Num of iterations = " << iter_cnt << endl;

	// Output result matrix
	// Show only 11x11 array with equally spaced rows and columns
	cout << "Result of calculation" << endl;
	UOutput(u_par, N);
	cout << endl;


	Submit_Part1(N, eps, Calc_seq);
	Submit_Part2(Calc_par_block);

	system("pause");

	return 0;
}