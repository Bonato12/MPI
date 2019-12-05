#include<stdio.h>
#include </usr/include/mpi/mpi.h>
#include<string.h>
int main(int argc, char **argv){
    int node;
    int nproc;
    int n;
    int i;
    char message[100];
    
    MPI_Status status;
    MPI_Init(&argc, &argv);
    //Determina el rango (identificador) del proceso que lo llama dentro del comunicador seleccionado.
    MPI_Comm_rank(MPI_COMM_WORLD, &node);
    //Ese número se llama el tamaño del comunicador
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    
    if (node == 1)/*Se le cambia por otro nodo*/{
        printf("Hola, soy el proceso 1 (hay %d procesos) y recibo: \n",nproc);
        for(i=1; i < nproc; i++){
    	    //Con i le decimos que reciva el mensaje de los procesos en orden
            //Rutina de recibimiento de un mensaje desde un proceso.
            MPI_Recv(message, 100, MPI_CHAR, i, 99, MPI_COMM_WORLD, &status);
            printf("%s", message);
        }
    }else{
        //Los demás procesos le envían mensaje al proceso 1
        printf("Hola desde el proceso %d\n",node);
        //Realiza el envío de un mensaje de un proceso fuente a otro destino.
        MPI_Send(message, strlen(message), MPI_CHAR, 1, 99, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
