#include <stdio.h>

int pedir_entero(void)
{
    int entero;
    printf("Ingrese un numero maximo de elemento para el arreglo: ");
    scanf("%d", &entero);
    return entero;
}

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

int main(void)
{
    int n_max;

    n_max = pedir_entero();

    int arreglo[n_max];

    pedir_arreglo(n_max, arreglo);
    imprimir_arreglo(n_max, arreglo);
}