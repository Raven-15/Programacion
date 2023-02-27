#include <stdio.h>

int main() {
    float celsius = 35;
    float fahrenheit = (celsius * 9/5) + 32;
    printf("La temperatura %.1f°C es igual a %.1f°F.", celsius, fahrenheit);
    return 0;
}
