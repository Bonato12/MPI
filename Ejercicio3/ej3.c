#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char *argv[]) {
 
 char mensaje[100];
 int rank, size, next, from, x,i;
 
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank); // numero de proceso.
 MPI_Comm_size(MPI_COMM_WORLD,&size); //cantidad de procesos.
 MPI_Status status;
 
 next = (rank + 1) % size;  //proceso siguiente
 from = (rank + size - 1) % size; //proceso anterior
 
if (rank == 0) {
	printf("Ingrese el numero de vueltas del anillo: \n");
	//scanf sirve para leer
	scanf("%d", &x); //guardamos el dato en la variable x con el simbolo &
	sprintf(mensaje,"El proceso %d envia el M%d al proceso %d\n",rank,rank,next);
	MPI_Send(mensaje,strlen(mensaje),MPI_CHAR, next, 99,MPI_COMM_WORLD);
}	
//Envía un mensaje desde un proceso origen a todos los procesos pertenecientes al mismo grupo.
MPI_Bcast(&x,1, MPI_INT, 0, MPI_COMM_WORLD); //mandar mensaje a todos (x).
	
while (x>0) {
	//recibe del anterior 	
	MPI_Recv(mensaje, 99, MPI_CHAR, from, 99,MPI_COMM_WORLD, &status);
    printf("%s",mensaje);

    x--; //restamos una vuelta
	
	if ((x >0) || (rank !=0) ){
		//envio al siguiente el mensaje.
		sprintf(mensaje,"El proceso %d envia al M%d al proceso %d\n",rank,rank,next); 
		MPI_Send(mensaje,strlen(mensaje),MPI_CHAR, next, 99,MPI_COMM_WORLD);
		
	}
 
}

MPI_Finalize();
return 0;

}
