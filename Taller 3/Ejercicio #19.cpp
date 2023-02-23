//Ejercicio #19

#include <stdio.h>

int main (){
	int num, i, numPrimo = 1;
	
	printf("Angelica digiste un numero entero: ");
	scanf("%d", &num);
	
	for (i = 2; i<= num / 2; i++){
		if (num % i == 0){
			numPrimo = 0;
		}
	}
	
	if (numPrimo == 1){
		printf("%d es primo. \n", num);
	}else{
		printf("%d no es primo. \n", num);
	}
	return 0;
}
