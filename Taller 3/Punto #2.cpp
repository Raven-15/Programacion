//Punto #2

#include <stdio.h>
#include <math.h>


double raiz(double n, double x) {
    double resul = pow(x, n);
    return resul;
}

int main() {
    int n, x;
    float resul;
    printf("Ingrese el valor de x: ");
	scanf("%d", &x);
	
	printf("Ingrese el valor de n: ");
	scanf("%d", &n);
	
    resul = pow(x, 1.0/n);
    printf("La raiz %d de %d es %.2f\n", n, x, resul);
    return 0;

}
