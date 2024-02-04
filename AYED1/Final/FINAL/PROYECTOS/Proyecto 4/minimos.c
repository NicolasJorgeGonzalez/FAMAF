#include <stdio.h>
#include <limits.h>

int minimo_pares(int tam, int a[])
{
    int i = 0;
    int min_par = INT_MAX; // Inicializamos min_par con el valor máximo de un entero para asegurarnos de que se actualice correctamente

    while (i < tam)
    {
        if ((a[i] % 2 == 0) && (a[i] < min_par))
        {
            min_par = a[i];
        }
        i++;
    }
    return min_par;
}

int minimo_impares(int tam, int a[])
{
    int i = 0;
    int min_impar = INT_MAX;

    while (i < tam)
    {
        if ((a[i] % 2 != 0) && a[i] < min_impar)
        {
            min_impar = a[i];
        }
        i++;
    }
    return min_impar;
}

int minimo_elemento(int minimo_impar, int minimo_par)
{
    int minimo_elemento;

    if (minimo_par <= minimo_impar)
    {
        minimo_elemento = minimo_par;
        return minimo_elemento;
    }
    else
    {
        minimo_elemento = minimo_impar;
        return minimo_elemento;
    }
}

int main(void)
{
    int tam_arreglo, minimo_impar, minimo_par, i = 0;

    printf("Ingrese cuantos elementos tendra su lista: ");
    scanf("%d", &tam_arreglo);

    int arreglo[tam_arreglo];

    while (i < tam_arreglo)
    {
        int valor;
        printf("Ingrese un valor para el elemento la posicion %d: ", i);
        scanf("%d", &valor);
        arreglo[i] = valor;
        i++;
    }

    minimo_impar = minimo_impares(tam_arreglo, arreglo);
    minimo_par = minimo_pares(tam_arreglo, arreglo);

    if (minimo_par == INT_MAX)
    {
        printf("No hay pares en la lista.\n");
        printf("El minimo impar es: %d.\n", minimo_impar);
        printf("El minimo elemento de la lista es: %d.\n", minimo_elemento(minimo_impar, minimo_impar));
    }
    if (minimo_impar == INT_MAX)
    {
        printf("El minimo par es: %d.\n", minimo_par);
        printf("No hay impares en la lista.\n");
        printf("El minimo elemento de la lista es: %d.\n", minimo_elemento(minimo_par, minimo_par));
    }
    else if ((minimo_par != INT_MAX) && (minimo_impar != INT_MAX))
    {
        printf("El minimo par es: %d.\n", minimo_par);
        printf("El minimo impar es: %d.\n", minimo_impar);
        printf("El minimo elemento es: %d.\n", minimo_elemento(minimo_impar, minimo_par));
    }
}