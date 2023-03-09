#include <stdio.h>

int main() {
   int x, y, i, j;

   for (i = 0; i < 10; i++) {
      x = i;
      y = 0;
      for (j = 0; j <= i; j++) {
         if (j == y) {
            y++;
         }
         else {
            x--;
         }
      }
      printf("%d %d\n", i, y);
   }

   return 0;
}
