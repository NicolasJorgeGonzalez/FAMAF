#include <stdio.h>
#include <stdbool.h>

int main(void){
    int x, y, z, b, w;

    printf("Ingrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);
    printf("Ingrese un valor para Z: ");
    scanf("%d", &z);
    printf("Ingrese un valor para B: ");
    scanf("%d", &b);
    printf("Ingrese un valor para W: ");
    scanf("%d", &w);

    printf("El resultado de la expresion X %% 4 == 0 = %s\n",x % 4 == 0 ? "True" : "False");
    printf("El resultado de la expresion X + Y == 0 && Y - X == (-1) * Z= %s\n",x + y == 0 && y - x == (-1) * z ? "True" : "False");
    printf("El resultado de la expresion not B && W = %s\n",!b && w ? "True" : "False");

    return 0;
}

//Ejemplos
// Ingrese un valor para X: 4
// Ingrese un valor para Y: -4
// Ingrese un valor para Z: 8
// Ingrese un valor para B: 1
// Ingrese un valor para W: 0
// El resultado de la expresion X % 4 == 0 = True
// El resultado de la expresion X + Y == 0 && Y - X == (-1) * Z= True
// El resultado de la expresion not B && W = False