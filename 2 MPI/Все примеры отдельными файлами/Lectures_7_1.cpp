#include "mpi.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int a[10] = { 0, 0, 0, 0, 0,
	              0, 0, 0, 0, 0 };
	int rank;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		for (int i = 0; i<10; i++)
			a[i] = i;
		MPI_Send(&a[0], 5, MPI_INT, 1, 99, MPI_COMM_WORLD);
	}
	else {
		MPI_Recv(&a[0], 10, MPI_INT, 0, 99, MPI_COMM_WORLD, &status);
		for (int i = 0; i<10; i++)
			cout << " recv: i=" << i << ": a[i]=" << a[i] << endl;
	}
	MPI_Finalize();
}

