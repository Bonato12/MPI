#include<stdio.h>
#include </usr/include/mpi/mpi.h>
#include<string.h>
int main(int argc, char **argv){
    int node;
    int nproc;
    int i;
    char message[100];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    //Determina el rango (identificador) del proceso que lo llama dentro del comunicador seleccionado.
    MPI_Comm_rank(MPI_COMM_WORLD, &node);
    //Ese número se llama el tamaño del comunicador
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    if (node != 0){
        //Los demás procesos le envían mensaje al proceso 0
        printf("Hola desde el proceso %d,\n",node);
        //Realiza el envío de un mensaje de un proceso fuente a otro destino.
        MPI_Send(message, strlen(message), MPI_CHAR, 0, 99, MPI_COMM_WORLD);  
    }else{
	printf("Hola, soy el proceso 0 (hay %d procesos) y recibo: \n",nproc);
        for(i=1; i < nproc; i++){
	    //Con i le decimos que reciva el mensaje de los procesos en orden
            MPI_Recv(message, 100, MPI_CHAR, i, 99, MPI_COMM_WORLD, &status);
            printf("%s", message);
        }
    }
    MPI_Finalize();
}
