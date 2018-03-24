#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#define NUM_THREADS	4
#define TAM      100
int tid;
int fila1[4];
pthread_mutex_t m1, m2;
int k=0;
int s=0;
int hora=7,min=0;

 void* banco(void* taskid){
   	int i,j;	
   	srand (time(NULL));
	int aleatorio=rand()%2;
	int aleatorio2= rand()%10;
	
	
	int tid = (int) taskid;
	if(tid==0){
	for (i=0; i<9;i++){
		hora++;
		min=0;		
		for(j=0; j<60; j++){			
		   if(hora==9&&min==0){
		   pthread_mutex_unlock(&m2);
		   }			
			printf ("La hora es %d y los minutos %d\n",hora,min);
			min++;			
			sleep(1);
		}
	   }
     }
     sleep(tid*aleatorio2);
     if(hora<9){
     pthread_mutex_lock(&m1);
     fila1[k]=tid;
     printf("Soy el hilo %d y estoy en la fila en la posicion %d\n",tid,k);
     k++;
     pthread_mutex_unlock(&m1);
      }
      pthread_mutex_lock(&m2);
      pthread_mutex_unlock(&m2);
      printf("Soy el hilo %d y entre al banco son las %d:%d\n",tid, hora,min);
     //cajas
     if(aleatorio==1){     
     printf("Soy el hilo %d y estoy en la caja\n",tid);
     
     }
     //servicio al cliente
     if(aleatorio==0){
     printf("Soy el hilo %d y estoy en el servicio a cliente\n",tid);
     }
     
      
        
      
     
     
 }

int main(int argc, char *argv[])
{

pthread_t threads[NUM_THREADS];
long taskids[NUM_THREADS];
int t;
int rc;
  pthread_mutex_init(&m1,NULL);
    pthread_mutex_init(&m2,NULL);
    pthread_mutex_lock(&m2);
for(t=0;t<NUM_THREADS;t++) {
  taskids[t] = t;
  rc = pthread_create(&threads[t], NULL, banco, (void *) taskids[t]);
  }
  
  for(t=0;t<NUM_THREADS;t++) 
  pthread_join(threads[t],NULL);
  


  

return 0;
}


