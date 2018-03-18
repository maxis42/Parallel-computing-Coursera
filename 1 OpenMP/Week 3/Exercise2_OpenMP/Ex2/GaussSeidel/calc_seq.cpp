#include "GaussSeidel.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>>

using namespace std;

// Block sequential algorithm of Gauss–Seidel method
int Calc_seq_block(double** u, double** f, int N, double eps) {

	double max_err = 0; // Max error
	double h = 1.0 / (N + 1); // Grid step

	int IterCnt = 0; // Iterations counter
	int BlockSize = 20; // Block size
	int BlockCount; // Number of blocks

	cout << fixed << setprecision(10);

	// Make calculations only if N % Blocksize == 0
	if (N % BlockSize == 0) {
		BlockCount = N / BlockSize;
		do {
			IterCnt++;
			max_err = 0;
			for (int IBlock = 0; IBlock < BlockCount; IBlock++) // Iterate blocks by i
				for (int JBlock = 0; JBlock < BlockCount; JBlock++)  // Iterate blocks by j
					for (int idx = 0; idx < BlockSize; idx++) // Block rows i
						for (int jdy = 0; jdy < BlockSize; jdy++) { // Block columns j
							// True current element indices
							int i = 1 + IBlock*BlockSize + idx;
							int j = 1 + JBlock*BlockSize + jdy;

							// Save previous value
							double u_old = u[i][j];

							// Gauss–Seidel method
							u[i][j] = 0.25*(u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - h*h*f[i-1][j-1]);

							// Current error with previous iteration
							double curr_err = abs(u[i][j] - u_old);

							// Update max error
							if (curr_err > max_err) max_err = curr_err;
						}
		} while (max_err > eps); // Do while desired tolerance not achieved
	}
	else {
		cout << "Error!!!" << endl;
	}
	return IterCnt;
}

// Sequential algorithm of Gauss–Seidel method
int Calc_seq(double** u, double** f, int N, double eps) {

	double max_err = 0; // Max error
	double h = 1.0 / (N + 1); // Grid step

	cout << fixed << setprecision(10);

	int IterCnt = 0; // Iterations counter

	do {
		IterCnt++;
		max_err = 0;
		for (int i = 1; i < N + 1; i++) // Array rows
			for (int j = 1; j < N + 1; j++) { // Array columns
				// Save previous value
				double u_old = u[i][j];

				// Gauss–Seidel method
				// u[i][j] <-> f[i-1][j-1] as u N+2xN+2, f NxN
				u[i][j] = 0.25*(u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - h*h*f[i-1][j-1]);

				// Current error with previous iteration
				double curr_err = abs(u[i][j] - u_old);

				// Update max error
				if (curr_err > max_err) max_err = curr_err;
			}

	} while (max_err > eps); // Do while desired tolerance not achieved
	return IterCnt;
}