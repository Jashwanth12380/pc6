
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, data_send, data_recv;


	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	data_send = rank;
	printf("\nDemonstrating Deadlock avoidance...");

		if (rank == 0)
		{
			MPI_Send(&data_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			printf("\nProcess 0 sent");
			MPI_Recv(&data_recv, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("\nProcess 0 received");
			
		
		}
		else if (rank == 1)
		{
			MPI_Send(&data_send, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			printf("\nProcess 1 sent");
			MPI_Recv(&data_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("\nProcess 1 received");
			
		}
   		printf("\nProcess %d received %d\n", rank, data_recv);
	MPI_Finalize();
	return 0;
}
