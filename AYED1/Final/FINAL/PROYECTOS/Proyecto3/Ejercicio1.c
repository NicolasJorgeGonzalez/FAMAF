#include <stdio.h>

int main(void){
    int x, y, z;

    printf("Ingrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);
    printf("Ingrese un valor para Z: ");
    scanf("%d", &z);

    printf("El resultado de la expresion X+Y+1= %d\n",x*y+1);
    printf("El resultado de la expresion Z*Z + Y*45 - 15*X= %d\n",z*z + y*45 - 15*x);
    printf("El resultado de la expresion Y-2 == (X * 3 + 1) %% 5= %s\n", (y - 2 == (x * 3 + 1) % 5) ? "True" : "False"); // El ? funciona como un condicional es una expresión condicional. Si la expresión entre paréntesis es verdadera, se imprimirá "True" y si es falsa, se imprimirá "False". 
    printf("El resultado de la expresion Y/2 * X= %d\n", y/2 * x);
    printf("El resultado de la expresion Y<X * Z= %s\n", y<x * z ? "True" : "False"); //El resultado tiene tipo String

    return 0;
}

// Ejemplos

// Ingrese un valor para X: 7 
// Ingrese un valor para Y: 3
// Ingrese un valor para Z: 5
// El resultado de la expresion X+Y+1= 22
// El resultado de la expresion Z*Z + Y*45 - 15*X= 55
// El resultado de la expresion Y-2 == (X * 3 + 1) % 5= False
// El resultado de la expresion Y/2 * X= 7
// El resultado de la expresion Y<X * Z= True

// Ingrese un valor para X: 1
// Ingrese un valor para Y: 10
// Ingrese un valor para Z: 8
// El resultado de la expresion X+Y+1= 11
// El resultado de la expresion Z*Z + Y*45 - 15*X= 499
// El resultado de la expresion Y-2 == (X * 3 + 1) % 5= False
// El resultado de la expresion Y/2 * X= 5
// El resultado de la expresion Y<X * Z= False