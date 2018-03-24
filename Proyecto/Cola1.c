#include <stdio.h>
#include <stdlib.h>



/*/////////////////////////////////////////////////////
<<<<<<<<<<<<<<<<	COLA 	>>>>>>>>>>>>>>>>>>>>>>>>>><
///////////////////////////////////////////////////////*/

//elementos para la cola

typedef struct{
	int tamcola;
	int frente;
	int posterior;
	int* arreglo;
	int tiempo_total;	
}Cola1;

Cola1 cola1;
//<<<<<<<<<<<<<<<<	METODOS DE LA COLA 	>>>>>>>>>>>>>>>>>>>>>>>>>><
void impCola1(){
	printf("[");
	for (int i = cola1.frente; i <cola1.tamcola; i++)
	{
		int aux=cola1.arreglo[i];
		printf("%d ",aux );
	}
	printf("]\n");
}

void iniciarCola1(){
	cola1.tiempo_total=0;
	cola1.frente=0;
	cola1.posterior=0;
	cola1.tamcola=4;
	cola1.arreglo=(int*)malloc(cola1.tamcola*sizeof(int));
	
	
}

void Encolar1(int dato){
	
	if( ((cola1.posterior+1) % cola1.tamcola) == cola1.frente){
		printf("Cola llena\n");
	}else{
		cola1.arreglo[cola1.posterior]=dato;
		cola1.posterior=(cola1.posterior+1)%cola1.tamcola;
	}
}

int Desencolar1(){
	
	if(cola1.frente == cola1.posterior){
		return -1000;
	}else{
		int aux=cola1.arreglo[cola1.frente];
		cola1.frente= (cola1.frente+1)%cola1.tamcola;
		
		return aux;
	}
}

int Esvacia1(){
	
	if(cola1.frente == cola1.posterior){
		return 1;
	}else{
		return 0;
	}
}

int main(){
iniciarCola1();

return(0);
}
