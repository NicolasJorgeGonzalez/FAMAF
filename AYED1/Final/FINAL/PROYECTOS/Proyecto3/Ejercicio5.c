#include <stdio.h>
#include <stdbool.h>

int main(void){
    //Punto A (H)
    int i, n;
    n = 0;

    printf("Punto A (H)\nIngrese un valor para I= ");
    scanf("%d", &i);

    while (i != 0){
        i -= 1;
        n += 1;
        printf("Estado Sigma %d de I= %d\n", n, i);
    }
    
    printf("El estado Final de I= %d\n\n", i);

    //Punto A (I)
    int h;
    n = 0;

    printf("Punto A (I)\nIngrese un valor para I= ");
    scanf("%d", &h);

    while (h != 0){
        h = 0;
        n += 1;
        printf("Estado Sigma %d de I= %d\n", n, h);
    }
    printf("Estado Final de H= %d\n\n",h);

    //Punto B (1) Division
    int x, y;
    n = 0;

    printf("Punto B (1)\nIngrese un valor para X= ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y= ");
    scanf("%d", &y);

    while (x >= y){
        x = x - y;
        n += 1;
        printf("El estado Sigma %d es X=%d Y=%d I=%d\n", n, x, y, n);
    }

    //Punto B (2) Primo o No Primo
    int k;
    bool res;

    n = 2;
    res = true;

    printf("\nPunto B (2)\nIngrese un valor para X= ");
    scanf("%d", &k);

    while ((n < k) && res){
        res = res && ((k % n) != 0);
        n += 1;
        printf("El estado Sigma %d es X= %d I= %d RES= %s\n", n-2, k, n, res ? "True" : "False");
    }
    
    return 0;
}
//Ejemplos
// Punto A (H)
// Ingrese un valor para I= 4
// Estado Sigma 1 de I= 3
// Estado Sigma 2 de I= 2
// Estado Sigma 3 de I= 1
// Estado Sigma 4 de I= 0
// El estado Final de I= 0

// Punto A (I)
// Ingrese un valor para I= 400
// Estado Sigma 1 de I= 0
// Estado Final de H= 0

// Punto B (1)
// Ingrese un valor para X= 13
// Ingrese un valor para Y= 3
// El estado Sigma 1 es X=10 Y=3 I=1
// El estado Sigma 2 es X=7 Y=3 I=2
// El estado Sigma 3 es X=4 Y=3 I=3
// El estado Sigma 4 es X=1 Y=3 I=4

// Punto B (2)
// Ingrese un valor para X= 5
// El estado Sigma 1 es X= 5 I= 3 RES= True
// El estado Sigma 2 es X= 5 I= 4 RES= True
// El estado Sigma 3 es X= 5 I= 5 RES= True