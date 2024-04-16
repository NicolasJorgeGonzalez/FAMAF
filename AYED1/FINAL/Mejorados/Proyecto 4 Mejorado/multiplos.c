#include <stdio.h>
#include <stdbool.h>
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

bool todos_pares(int tam, int a[])
{
    int i = 0;
    bool estadoBool = true;
    while (i != tam)
    {
        estadoBool = estadoBool && (((a[i]) % 2) == 0);
        i++;
    }
    return estadoBool;
}

bool existe_multiplo(int m, int tam, int a[])
{
    int i = 0;
    bool estadoBool = false;

    while (i != tam)
    {
        estadoBool = estadoBool || (((a[i]) % m) == 0);
        i++;
    }
    return estadoBool;
}

int main(void)
{
    int arreglo[N], opcion, m;
    pedir_arreglo(N, arreglo);

    printf("1. Todos pares\n");
    printf("2. Existe multiplo\n");
    printf("Escoja una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("El resultado de ejecutar la funcion es: %s\n", todos_pares(N, arreglo) ? "True" : "False");
        break;
    case 2:
        printf("De que numero desea buscar un multiplo? ");
        scanf("%d", &m);
        printf("El resultado de ejecutar la funcion es: %s\n", existe_multiplo(m, N, arreglo) ? "True" : "False");
        break;
    }
}
