/*
 ============================================================================
 Name        : Colectivas.c
 Author      : Miguel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello MPI World in C 
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mpi.h"
#include<stdlib.h>

int main(int argc, char* argv[]){
	int  tid; /* rank of process */
	int  n;       /* number of processes */
	int  i,j;
int hora=7, min=0;
int tiempo[2];
int aleatorio2,aleatorio;
int k;
int cliente;
int cajeros=3;
int aux=0;
MPI_Status status;
MPI_Request request;
	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &tid);
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &n);
sleep(tid);        
srand (time(NULL));
aleatorio2= rand()%10;    
aleatorio= rand()%2;
       if(tid==0){
for (i=0; i<9;i++){
           hora++;
           min=0;
for(j=0; j<60; j++){
      printf ("La hora es %d y los minutos %d\n",hora,min);
      tiempo[0]=hora;
      tiempo[1]=min;
    if(hora==9&&min==0){
    MPI_Bcast(&tiempo,2,MPI_INT,0,MPI_COMM_WORLD);
   //  MPI_Send(&tiempo,2,MPI_INT,1,123,MPI_COMM_WORLD);
           }
MPI_Irecv(&aux,1,MPI_INT,MPI_ANY_SOURCE,3,MPI_COMM_WORLD,&request);
 MPI_Isend(&tiempo,2,MPI_INT,aux,3,MPI_COMM_WORLD,&request);

      min++;
        sleep(1);
  
      }
     }
  }

	printf("soy el proceso %d llego al banco pero esta cerrado\n",tid);
          MPI_Bcast(&tiempo,2,MPI_INT,0,MPI_COMM_WORLD);

	//MPI_Recv(&tiempo,2,MPI_INT,0,123,MPI_COMM_WORLD,&status);

	//MPI_Barrier(MPI_COMM_WORLD);

        MPI_Isend(&tid,1,MPI_INT,0,3,MPI_COMM_WORLD,&request);
       MPI_Irecv(&tiempo,2,MPI_INT,0,3,MPI_COMM_WORLD,&request);

	printf("%d:%d soy el proceso %d entro al banco \n",tiempo[0],tiempo[1],tid);

//cajas
if(aleatorio==1){
 MPI_Isend(&tid,1,MPI_INT,0,3,MPI_COMM_WORLD,&request);
  MPI_Irecv(&tiempo,2,MPI_INT,0,3,MPI_COMM_WORLD,&request);
printf("%d:%d Soy el proceso  %d y estoy en la caja\n",tiempo[0],tiempo[1],tid); 
if(tid<=cajeros){
MPI_Irecv(&cliente,1,MPI_INT,MPI_ANY_SOURCE,123,MPI_COMM_WORLD,&request);
printf("Soy el proceso %d y estoy con el cajero %d\n",cliente,tid);
rand()%10;
MPI_Isend(&tid,1,MPI_INT,k,123,MPI_COMM_WORLD,&request);

}else{
for(k=1;k<=cajeros;k++){
MPI_Isend(&tid,1,MPI_INT,k,123,MPI_COMM_WORLD,&request);
    }
  }
 }

//servicio al cliente
if(aleatorio==0){
printf("Soy el proceso %d y estoy en el servicio a cliente\n",tid);
}


	//MPI_Bcast(&dato,1,MPI_INT,0,MPI_COMM_WORLD);

	
//printf("final de BCAST el valor de dato es %d soy %d\n",dato,tid);


	MPI_Finalize(); 
	
	
	return 0;
}
