#include <stdio.h>
#define N 5

void pedir_arreglo(int n_max, int a[])
{
    int numeroIngresado;

    for (int i = 0; i < n_max; i++)
    {
        printf("Ingrese un numero para agregar al arreglo: ");
        scanf("%d", &numeroIngresado);
        a[i] = numeroIngresado;
    }
}

int sumatoria(int tam, int a[])
{
    int resultado = 0;

    for (int i = 0; i < tam; i++)
    {
        resultado += a[i];
    }
    return resultado;
}

int main(void)
{
    int arreglo[N], resultado;

    pedir_arreglo(N, arreglo);

    resultado = sumatoria(N, arreglo);

    printf("El resultado de sumar todos los elementos del arreglo es: %d\n", resultado);

    return 0;
}