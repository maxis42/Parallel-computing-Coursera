#include "mpi.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// Определение параметров задачи
	int const n = 10;
	int const m = n / size;
	double a[n*n];
	double x[n], y[n], y1[n];

	// Задание начальных значений
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {	
			// Задаем диагональную матрицу с единицами на главной диагонали
			if (i + rank*m == j)
				a[i*n + j] = 1;
			else
				a[i*n + j] = 0;
		}
	}
				
	for (int i = 0; i < n; i++) {
		x[i] = i;
	}
	
	double time_work = 0;
	if (rank == 0) {
		time_work = MPI_Wtime();
	}

	// Проведение вычислений
	for (int i = 0; i<m; i++) {
		y1[i] = 0;
		for (int j = 0; j<n; j++) {
			y1[i] = y1[i] + a[i*n + j] * x[j];
		}
	}

	// Сбор данных на нулевом процессе
	MPI_Gather(&y1[0], m, MPI_DOUBLE, &y[0], m, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	// Выдача результатов на экран	
	if (rank == 0) {
		time_work = MPI_Wtime() - time_work;
		cout << " The Program is RUN on " << size << " CPU" << endl;
		cout << "Time     = " << time_work << endl;
		for (int i = 0; i<n; i++) 
			cout << " y[" << i << "]= " << y[i]  << endl;
	}

	MPI_Finalize();
	return 0;
}
