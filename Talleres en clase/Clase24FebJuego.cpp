#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	
	printf ("                             BIENVENIDO AL JUEGO DE ADIVINANZA \n\n ");
	
	int secret_number, attempts = 0, max_attempts = 10, riddle;
	
	srand (time(NULL));
	secret_number = rand () % 100 + 1;
	

	printf ("Tienes %d intentos para adivinar el numero secreto entre 1 y 100  ", max_attempts);
	
	
	do{
		
		printf("Introduce tu adivinanza \n");
		scanf ("%d", &riddle);
		attempts++;
		
		if (riddle > secret_number) {
			printf ("Demasiado alto, intenta de nuevo  ");
		} else if (riddle < secret_number ){
			printf ("Demasiado bajo, intenta de nuevo  ");
		}else {
			printf ("Felicitaciones adivinaste el numero %d en %d intentos \n ", secret_number, attempts) ;
			break; 
		}
		
	}while (attempts < max_attempts);
	
	if (attempts = max_attempts){
		printf ("Lo siento has agotado tus intentos !!");
	}
	
	return  0;
}
