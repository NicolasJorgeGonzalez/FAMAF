#include <stdio.h>
#include <assert.h>

int suma_hasta(int n){
    int sum_parc,N;
    N = n;
    sum_parc = 0;
    while (n != 0){
        sum_parc += n;
        n -= 1;
    }
    
    printf("La suma de 0 hasta %d es: %d\n", N, sum_parc);
    return 0;
}

int main(void){
    int n;

    printf("Hasta que numero desea sumar: ");
    scanf("%d", &n);
    assert(n > 0);

    suma_hasta(n);
    return 0;
}