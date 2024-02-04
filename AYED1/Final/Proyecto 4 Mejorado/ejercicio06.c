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
}

int main(void)
{
    int n_max;
    int arreglo[n_max];

    n_max = pedir_entero();

    imprimir_arreglo()
}