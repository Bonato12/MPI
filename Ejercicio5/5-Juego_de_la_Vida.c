integer ciclo_vida = 200, 
integer filas = 20, 
integer columnas = 20, 
integer vecinos = 0, 
integer nuevos_vecinos = 0,
char poblacion[filas][columnas];

funcion Inicializar_Matriz(){
	for(int i = 0; i < filas; i++){
		for(int j = 0; i < columnas; j++){
			poblacion[i][j] = '0';
		}
	}
}

funcion Poblar_Aleatorio(){
	for(int i = 0; i < filas; i++){
		for(int j = 0; i < columnas; j++){
			if(poblacion[i][j] == '0')
			poblacion[i][j] = '1';
		}
	}
}

funcion Mostrar_Poblacion(){
	for (int i = 0; i < filas; i++){
            printf("\n");
        for (int j = 0; j < columnas; j++){
            printf("%d",poblacion[i][j] );
        }
    }
    printf("\n");
}

funcion Vecinos_Cercanos(int posf, int posc){

	if (posf -1 >= 0 && posc -1 >= 0){
		
		if (poblacion[posf-1][posc-1] == '1')
			vecinos++;
	}
	if(posf-1 >= 0){
		
		if (poblacion[posf-1][posc-1] == '1')
			vecinos++;
	}
	if(posf-1 >= 0 && posc+1 <= columnas-1){
		
		if (poblacion[posf-1][posc-1] == '1')
			vecinos++;
	}
	if(posc-1 >= 0){
		
		if (poblacion[posf-1][posc] == '1')
			vecinos++;
	}
	if(posc+1 <= columnas-1){
		
		if (poblacion[posf-1][posc+1] == '1')
			vecinos++;
	}
	if(posf+1 <= filas-1 && posc-1 >= 0){
		
		if (poblacion[posf][posc-1] == '1')
			vecinos++;
	}
	if(posf+1 <= filas-1){
		
		if (poblacion[posf+1][posc-1] == '1')
			vecinos++;
	}
	if(posf+1 <= filas-1 && posc+1 <= columnas-1){
		
		if (poblacion[posf+1][posc+1] == '1')
			vecinos++;
	}
	
	
	return vecinos;
}

funcion Nueva_Poblacion(){
	for(int i = 0; i < filas; i++){
		for(int j = 0; i < columnas; j++){
			nuevos_vecinos = Vecinos_Cercanos(i,j);
			//Condición de nacimiento
			if(poblacion[i][j] == '0'){
				if (nuevos_vecinos == 3)
					poblacion[i][j] = '1';
				else
					poblacion[i][j] = '0';
			}
			//Condición de Supervivencia
			else if(poblacion[i][j] == '1'){
				if (nuevos_vecinos == 2 || nuevos_vecinos == 3)
					poblacion[i][j] = '1';
				else
					poblacion[i][j] = '0';
			}
		}
	}
}

int main(int argc, char *argv[])
{
 integer i=0;
 Inicializar_Matriz();
 Poblar_Aleatorio();
 while(i < ciclo_vida){
  	Mostrar_Poblacion();
  	Nueva_Poblacion();
  	i++;
 }

return 0;
}