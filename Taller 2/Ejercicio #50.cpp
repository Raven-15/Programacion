#include <stdio.h>

int main() {
   int a = 0, b = 1, c, i, j;

   for (i = 0; i <= 7; i++) {
      if (i == 0) {
         printf("%d %d\n", a, b);
      } else {
         c = a + b;
         a = b;
         b = c;
         if (i == 4) {
            printf("%d %d\n", a, b);
         }
         if (i >= 5) {
            printf("%d%d\n", a, i-2);
         }
      }
   }

   return 0;
}
