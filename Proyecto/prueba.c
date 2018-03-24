#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include "Cola1.h"


int main(){

	
	Encolar1(1);
	Encolar1(2);
	impCola1();
	Desencolar1();
	Desencolar1();
	Encolar1(81);
	Encolar1(91);
	impCola1();
	
	return 0;
}
