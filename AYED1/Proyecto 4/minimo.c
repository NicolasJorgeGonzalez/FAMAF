#include <stdio.h>
#include <assert.h>

int main(void){
    int x,y,minimo;
    printf("Ingresar el valor de X: ");
    scanf("%d", &x);
    printf("Ingresar el valor de Y: ");
    scanf("%d", &y);

    if (x < y){
        minimo = x;
    }
    else{
        minimo = y;
    }
    assert(minimo == x || minimo == y);
    printf("El minimo ente %d y %d es %d \n", x,y, minimo);
}