#include "mpi.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int rank;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		int a[5];
//		for (int i = 0; i < 5; i++) 
//			a[i] = i;
		MPI_Send(&a[0], 3, MPI_INT, 1, 99, MPI_COMM_WORLD);
	}
	else {
		int b[5];
		MPI_Recv(&b[0], 3, MPI_INT, 0, 99, MPI_COMM_WORLD, &status);
//		for (int i = 0; i < 5; i++)
//			cout << " recv: i=" << i << ": b[i]=" << b[i] << endl;
	}
	MPI_Finalize();
}