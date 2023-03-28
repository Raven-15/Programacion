#include <stdio.h>

int main() {
   int x, y, z, i, j;

   for (i = 1; i <= 9; i++) {
      x = (i - 1) / 3 + 1;
      y = (i - 1) % 3 + 1;
      z = (i - 1) % 2 + 1;
      printf("%d %d %d\n", x, y, z);
   }

   return 0;
}
