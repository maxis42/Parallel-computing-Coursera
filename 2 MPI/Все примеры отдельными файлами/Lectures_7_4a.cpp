#include "mpi.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int rank, size;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int dest = rank + 1;   // получатель
	int source = rank - 1; // отправитель
	if (rank == 0) source = MPI_PROC_NULL;
	if (rank == size - 1) dest = MPI_PROC_NULL;

	int sum = 0;
	int a = rank;
	MPI_Recv(&sum, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
	sum = sum + a;
	MPI_Send(&sum, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
	cout << "Rank = " << rank << ": sum = " << sum << ":" << endl;
	MPI_Finalize();
}

