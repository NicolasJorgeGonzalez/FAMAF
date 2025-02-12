#include <stdio.h>
#include <assert.h>

int main(void){
    int x, valor_abs;
    printf("Ingrese un numero: ");
    scanf("%d", &x);

    if (x >= 0){
        valor_abs = x;
    }
    else{
        valor_abs = x * (-1);
    }
    assert(valor_abs == x || valor_abs == -x);
    printf("El valor absoluto de %d es: %d\n", x, valor_abs);
    return 0;
}