#include <stdio.h>

int main(void){
    //Punto A
    int x;
    printf("Punto a)\nEstado inicial de X: ");
    scanf("%d", &x);

    x = 5;

    printf("Estado final de X es: %d\n", x);

    //Punto B
    int a,b;
    
    printf("\nPunto b)\nEstado inicial de A: ");
    scanf("%d", &a);
    printf("Estado inicial de B: ");
    scanf("%d", &b);

    a= a+b;
    b= b+b;

    printf("Estado final de A es: %d\n", a);
    printf("Estado final de B es: %d\n", b);

    //Punto C
    int c,d;

    printf("\nPunto c)\nEstado inicial D: ");
    scanf("%d", &d);
    printf("Estado inicial C: ");
    scanf("%d", &c);

    d= d+d;
    c= c+d;

    printf("Estado final de D: %d\n", d);
    printf("Estado final de C: %d\n", c);

    return 0;
}

//Primera ejecucion
// Punto A)
// Estado inicial de X: 4
// Estado final de X es: 5

// Punto B)
// Estado inicial de A: 2
// Estado inicial de B: 1
// Estado final de A es: 3
// Estado final de B es: 2

// Punto C)
// Estado inicial D: 5
// Estado inicial C: 3
// Estado final de D: 10
// Estado final de C: 13

//Segunda ejecucion
// Punto A)
// Estado inicial de X: 6
// Estado final de X es: 5

// Punto B)
// Estado inicial de A: 3
// Estado inicial de B: 8
// Estado final de A es: 11
// Estado final de B es: 16

// Punto C)
// Estado inicial D: 5
// Estado inicial C: 3
// Estado final de D: 10
// Estado final de C: 13

//Tercera ejecucion
// Punto A)
// Estado inicial de X: 9
// Estado final de X es: 5

// Punto B)
// Estado inicial de A: 4
// Estado inicial de B: 1
// Estado final de A es: 5
// Estado final de B es: 2

// Punto C)
// Estado inicial D: 8
// Estado inicial C: 5
// Estado final de D: 16
// Estado final de C: 21