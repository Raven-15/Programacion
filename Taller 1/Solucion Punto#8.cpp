#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main (void)
{
    float centimetros, kilometros, metros;
   
    printf("\nIngrese un valor en metros: ");
	scanf("%f",&metros);
	
    //milimetros=metros*1000;
    centimetros=metros*100;
    //decimetros=metros*10;
    //hectometros=metros/100;
    kilometros=metros/1000;
    
	printf("\nEquivale en centimetros a: %f", centimetros);
	printf("\nEquivale en kilometros a: %f", kilometros);
	
	return 0;
}
