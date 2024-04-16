#include <stdio.h>

int main(void){
    //Punto A (E y F son el mismo codigo)
    int x, y;
    
    printf("Punto A\nIngrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);

    if (x >= y){
        printf("\nEl Estado Sigma 1 de (X >= Y) X= %d Y= %d es: %s\n", x, y , x >= y ? "True" : "False");
        x = 0;
        printf("El Estado Sigma 2 de (X >= Y) X= %d Y= %d es: %s\n", x, y , x >= y ? "True" : "False");
    }
    else if (x <= y){
        printf("\nEl Estado Sigma 1 de (X <= Y) X= %d Y= %d es: %s\n", x, y , x <= y ? "True" : "False");
        x = 2;
        printf("El Estado Sigma 2 de (X <= Y) X= %d Y= %d es: %s\n", x, y , x <= y ? "True" : "False");
    }
    printf("El estado Sigma Final de X= %d y de Y= %d\n\n", x,y);

    //Punto B
    int a, b, c, d;

    printf("Punto B\nIngrese un valor para A= ");
    scanf("%d", &a);
    printf("Ingrese un valor para B= ");
    scanf("%d", &b);
    printf("Ingrese un valor para C= ");
    scanf("%d", &c);
    printf("Ingrese un valor para D= ");
    scanf("%d", &d);

    printf("\nEl estado Inicial es A=%d B=%d C=%d D=%d\n", a, b, c, d);
    if (a < b){
        d = a;
    }
    else{
        d = b;
    }
    
    printf("El estado Sigma es A=%d B=%d C=%d D=%d\n", a, b, c, d);
    if (d >= c){
        d = c;
    }
    
    printf("El estado Sigma Final es A=%d B=%d C=%d D=%d\n", a, b, c, d);

    

    return 0;
}

//Ejemplos
// Punto A (E)
// Ingrese un valor para X: 3
// Ingrese un valor para Y: 1

// El Estado Sigma 1 de (X >= Y) X= 3 Y= 1 es: True
// El Estado Sigma 2 de (X >= Y) X= 0 Y= 1 es: False
// El estado Sigma Final de X= 0 y de Y= 1

// Punto A (F)
// Ingrese un valor para X: -100
// Ingrese un valor para Y: 1

// El Estado Sigma 1 de (X <= Y) X= -100 Y= 1 es: True
// El Estado Sigma 2 de (X <= Y) X= 2 Y= 1 es: False
// El estado Sigma Final de X= 2 y de Y= 1

// Punto B
// Ingrese un valor para A= 5
// Ingrese un valor para B= 4
// Ingrese un valor para C= 8
// Ingrese un valor para D= 0

// El estado Inicial es A=5 B=4 C=8 D=0
// El estado Sigma es A=5 B=4 C=8 D=4
// El estado Sigma Final es A=5 B=4 C=8 D=4

// Punto B
// Ingrese un valor para A= 4
// Ingrese un valor para B= 7
// Ingrese un valor para C= 12
// Ingrese un valor para D= 3

// El estado Inicial es A=4 B=7 C=12 D=3
// El estado Sigma es A=4 B=7 C=12 D=4
// El estado Sigma Final es A=4 B=7 C=12 D=4