#include "mpi.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int const n = 10;
	int n1 = n / size;
	int a[n],  b[n],  c[n];
	int a1[n], b1[n], c1[n];
	
	// Заполнение массивов
	if (rank == 0)	
		for (int i = 0; i < n; i++)			
		{
			a[i] = rand() % 10;
			b[i] = rand() % 10;
		}		
    // Распределение данных с нулевого процесса
	MPI_Scatter(&a[0], n1, MPI_INT, &a1[0], n1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(&b[0], n1, MPI_INT, &b1[0], n1, MPI_INT, 0, MPI_COMM_WORLD);

	// Вычисления
	for (int i = 0; i <= n1; i++)
		c1[i] = a1[i] + b1[i];
	
	// Сбор данных на нулевом процессе
	MPI_Gather(&c1[0], n1, MPI_INT, &c[0], n1, MPI_INT, 0, MPI_COMM_WORLD);

	//Выдача результатов
	if (rank == 0) {
		cout << "        a[i]  b[i]  c[i]" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << " i= " << i << "     " << a[i] << "     " << b[i] << "     " << c[i] << endl;
		}
	}

	MPI_Finalize();
	return 0;
}
