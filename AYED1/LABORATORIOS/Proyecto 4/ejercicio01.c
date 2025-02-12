#include <stdio.h>
#include <assert.h>

void hola_hasta(int n){
    while (n != 0){
        printf("Hola\n");
        n -= 1;
    }
}

int main(void){
    int n;
    printf("Cuantas veces desea imprimir Hola: ");
    scanf("%d", &n);
    assert(n > 0);
    hola_hasta(n);
    return 0;
}