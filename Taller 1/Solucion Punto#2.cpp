#include <stdio.h>
#include <stdlib.h>

int main (){
	
	float vi, t1, ti2, ace, ms, d, vf; 
	
	
	//pasar de km/h a m/s
	
	vf=100;
	ms=vf/3.6;
	vf=ms;
	
	//printf("Velocidad final en metros sobre segundos: %f \n", vf);
	
	//inicializamos las variables conocidas
	
	vi=0;
	t1=35;
	ti2=20;	
	
	//calculo de la aceleracion en 35s
	
	ace=(vf-vi)/t1;
	
	//printf("Aceleracion: %f \n", ace);
	
	//calculo de la distancia a los 20s
	
	d=(ace*ti2)/2;
	printf("La distancia del auto pasados 20s es de: %f \n", d);
	
	return 0;	
}


