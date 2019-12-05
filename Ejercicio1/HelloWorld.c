#include<stdio.h>
#include </usr/include/mpi/mpi.h>

//Puntero al número de argumentos,Puntero al vector de argumentos
main(int argc, char **argv){
int node;
// Inicializacion
MPI_Init(&argc, &argv);

//Determina el rango (identificador) del proceso que lo llama dentro del comunicador seleccionado.
MPI_Comm_rank(MPI_COMM_WORLD, &node);
printf("Hola Mundo desde el proceso %d\n",node);
// Finalizacion
MPI_Finalize();
}