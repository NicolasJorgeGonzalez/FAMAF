#include <stdio.h>
#include <assert.h>
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

void imprimir_arreglo(int n_max, int a[])
{
    for (int i = 0; i < n_max; i++)
    {
        printf("El valor en la posicion %d es %d\n", (i + 1), a[i]);
    }
}

void intercambiar(int a[], int i, int j)
{
    int posicion1, posicion2;
    posicion1 = i;
    posicion2 = j;

    a[posicion1] = a[posicion2];
    a[posicion2] = a[posicion1];
}

int main(void)
{
    int arreglo1[N], posicion1, posicion2;

    pedir_arreglo(N, arreglo1);

    printf("Ingrese que posicion desea intercambiar: ");
    scanf("%d", &posicion1);

    printf("Ingrese con cual posicion desea intercambiarla: ");
    scanf("%d", &posicion2);

    assert((posicion1 >= 0 && posicion1 < N) && (posicion2 >= 0 && posicion2 < N));

    intercambiar(arreglo1, posicion1, posicion2);
    imprimir_arreglo(N, arreglo1);

    return 0;
}