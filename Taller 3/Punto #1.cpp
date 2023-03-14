//Punto #1

#include <stdio.h>

int potencia(int x, int n){
	int i, p = x;
	for(i = 1; i < n; i++){
		p *= x;
	}
	return p;
}

int main(){
	int x, n;
	
	printf("Ingrese el valor de x: ");
	scanf("%d", &x);
	
	printf("Ingrese el valor de n: ");
	scanf("%d", &n);
	
	printf("%d elevado a la potencia %d es igual a %d", x,n, potencia(x, n));
	
	return 0;
}
