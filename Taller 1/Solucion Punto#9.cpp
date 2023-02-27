#include <stdio.h>

int main() {
   float kilobytes, gigabytes, bits;

   printf("Ingrese una cantidad en KiloBytes: ");
   scanf("%f", &kilobytes);

   gigabytes = kilobytes / 1048576;
   bits = kilobytes * 8192;

   printf("%f KiloBytes equivalen a %f GigaBytes\n", kilobytes, gigabytes);
   printf("%f KiloBytes equivalen a %f bits\n", kilobytes, bits);

   return 0;
}
