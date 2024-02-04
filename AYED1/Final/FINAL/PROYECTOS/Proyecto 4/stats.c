#include <stdio.h>
#include <limits.h>

typedef struct
{
    float maximo;
    float minimo;
    float promedio;
} datos_t;

datos_t stats(int tam, float a[])
{
    int i = 0, sum_elem = 0;

    datos_t totales;
    totales.maximo = INT_MIN;
    totales.minimo = INT_MAX;

    while (i < tam)
    {
        if (a[i] > totales.maximo)
        {
            totales.maximo = a[i];
        }
        else if (a[i] < totales.minimo)
        {
            totales.minimo = a[i];
        }
        sum_elem += a[i];
        i++;
    }

    totales.promedio = sum_elem / tam;

    return totales;
}

int main(void)
{
    int arreglo_tam, i = 0;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &arreglo_tam);

    float arreglo[arreglo_tam];

    while (i < arreglo_tam)
    {
        float valor;
        printf("Ingrese un valor para el elemento %d del arreglo: ", i + 1);
        scanf("%f", &valor);
        arreglo[i] = valor;
        i++;
    }

    datos_t resultados = stats(arreglo_tam, arreglo);

    printf("El maximo de la lista es: %f\n", resultados.maximo);
    printf("El minimo de la lista es: %f\n", resultados.minimo);
    printf("El promedio de la lista es: %f\n", resultados.promedio);

    return 0;
}