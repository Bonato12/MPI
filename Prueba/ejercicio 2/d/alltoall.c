// alltoall implementado con send y recv, auqnue de momento solo funciona para 3
// procesos solamente.

#include <stdio.h>
#include <string.h>
#include </usr/include/mpi/mpi.h>

int main(int argc, char **argv){

    int my_rank, nproc;
    char message;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    char v1[4] = "123";
    char v2[4] = "456";
    char v3[4] = "789";

    char * m[3] = {v1, v2, v3}; 


    for (int j = 0; j < 3; j++) {

        MPI_Send(&m[my_rank][j], 1, MPI_CHAR, j, 99, MPI_COMM_WORLD);

    }

    printf("soy el proceso %d y recibi: ", my_rank);
    for (int i = 0; i < 3; i++) {
        MPI_Recv(&message, 2, MPI_CHAR, i, 99, MPI_COMM_WORLD, &status);
        printf("%c ", message);
    }
    printf("\n");

    MPI_Finalize();
    
}