// los mensajes son asincronos

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){

    int producto, num_procs, my_rank, num, mensaje;
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    num = my_rank + 1;
    // Rango del proceso destino 0, 99
    // &num es lo que quiero mandar
    // MPI_INT es el tipo de dato
    // Dato de tipo MPI_Request, en el se guarda una etiqueta que identifica la operación no bloqueante
    MPI_Isend(&num, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &request);
    //Bloquea al proceso hasta que termine la operación de envío o de recibo especificada.
    MPI_Wait(&request, &status);

    if (my_rank == 0) {
        producto = 1;
        for(int i=0;i<num_procs;i++){
            //Operación de recibo de mensaje no bloqueante.
            MPI_Irecv(&mensaje, 1, MPI_INT, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &request);
            MPI_Wait(&request, &status);
            producto = mensaje * producto;
        }
        
        printf("Hola, soy el proceso %d y el factorial de %d es %d\n", my_rank, num_procs, producto);
    }

    MPI_Finalize();

}