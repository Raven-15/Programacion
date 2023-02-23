#include <stdio.h>

int main (){

	int num;
	printf("Ingrese un numero de tres cifras: \n");
	scanf ("%d", &num);
	
	int a,b,c,d;
	
	a = num/100;
	b = num%100;
	c = b/10;
	d = b%10;
	
	printf("%d \n",a);
	printf("%d \n",b);
	printf("%d \n",c);
	printf("%d \n",d);
	printf("%d%d \n",a,c);	
	
	return 0;
	
}
