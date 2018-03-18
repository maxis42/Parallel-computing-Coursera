#include "GaussSeidel.h"
#include "omp.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace std;

// Block parallel algorithm of Gauss–Seidel method
int Calc_par_block (double** u, double** f, int N, double eps) {

	double max_err = 0; // Max error
	double h = 1.0 / (N + 1); // Grid step

	int IterCnt = 0; // Iterations counter
	int BlockSize = 20; // Block size
	int BlockCount; // Number of blocks

	cout << fixed << setprecision(10);

	// Make calculations only if N % Blocksize == 0
	if (N % BlockSize == 0) {
		BlockCount = N / BlockSize;
		int num_of_waves = BlockCount * 2 - 1;

		do {
			IterCnt++;
			max_err = 0;

			int num_of_elems_wave = 0;
			int row_start = 0;
			int col_start = -1;
			// Iterate through waves
			for (int i_wave = 0; i_wave < num_of_waves; i_wave++) {
				if (i_wave < BlockCount) {
					num_of_elems_wave += 1;
					col_start += 1;
				}
				else {
					num_of_elems_wave -= 1;
					row_start += 1;
				}

				if (col_start >= BlockCount) cout << "Error colstart" << endl;
				if (row_start >= BlockCount) cout << "Error rowstart" << endl;

				if (num_of_elems_wave == 0) cout << "Error num_of_elems_wave" << endl;

				// Iterate through blocks in wave
				#pragma omp parallel shared(max_err)
				#pragma omp for schedule(dynamic, 1)
				for (int i_wave_elem = 0; i_wave_elem < num_of_elems_wave; i_wave_elem++) {
					double max_err_wave = max_err;
					//Iterate through elements inside the block
					for (int idx = 0; idx < BlockSize; idx++) // Block rows i
						for (int jdy = 0; jdy < BlockSize; jdy++) { // Block columns j
							// True current element indices
							int i = (row_start + i_wave_elem)*BlockSize + idx + 1;
							int j = (col_start - i_wave_elem)*BlockSize + jdy + 1;

							// Save previous value
							double u_old = u[i][j];

							// Gauss–Seidel method
							u[i][j] = 0.25*(u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - h * h*f[i - 1][j - 1]);

							// Current error with previous iteration
							double curr_err = abs(u[i][j] - u_old);

							// Update max error
							if (curr_err > max_err_wave) max_err_wave = curr_err;
						}
					#pragma omp critical
					{
						if (max_err_wave > max_err) max_err = max_err_wave;
					}
				}
			}
		} while (max_err > eps); // Do while desired tolerance not achieved
	}
	else {
		cout << "Error!!!" << endl;
	}
	return IterCnt;
}
