
#include <stdio.h>
#include <stdbool.h>
#define N 8

int main(void)
{
    int cima;
    int arreglo[N] = {1, 2, 3, 4, 5, 4, 3, 2};
    int incio = 0;
    int fin = N - 1;

    while (incio < fin)
    {
        int mid = incio + (fin + incio) / 2;

        if (arreglo[mid] < arreglo[mid + 1])
        {
            incio = mid + 1;
        }
        else if (arreglo[mid] > arreglo[mid + 1])
        {
            fin = mid;
        }
    }
    cima = incio;
    printf("La cima se encuentra en %d", cima);
}