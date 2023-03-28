//Ejercicio #19

#include <stdio.h>

int main (){
	int n, i, numPrimo = 1;
	
	printf("Angelica digite un numero entero: ");
	scanf("%d", &n);
	
	for (i = 2; i<= n / 2; i++){
		if (n % i == 0){
			numPrimo = 0;
		}
	}
	
	if (numPrimo == 1){
		printf("%d es primo. \n", n);
	}else{
		printf("%d no es primo. \n", n);
	}
	return 0;
}
