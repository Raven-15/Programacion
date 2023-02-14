#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main (void)
{
    float Kilobyte, Gigabyte, bits;
   
    printf("\nIngrese un valor en Kb: ");
	scanf("%f",&Kilobyte);
	
    Gigabyte=Kilobyte/1000000;
    bits=Kilobyte*8000;
    
	printf("\nEquivale en Gigabytes a: %f", Gigabyte);
	printf("\nEquivale en Bits a: %f", bits);
	
	return 0;
}
