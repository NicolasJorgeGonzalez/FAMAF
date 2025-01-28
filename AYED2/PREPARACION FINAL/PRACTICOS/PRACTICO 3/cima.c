#include <stdio.h>
#include <stdbool.h>
#define N 8

int main(void)
{
    bool tiene_cima = true;
    int arreglo[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    int cima = 0;

    for (unsigned int i = 1; i < N; i++)
    {
        if (arreglo[i - 1] > arreglo[i])
        {
            cima = i - 1;
            break;
        }
    }
    for (unsigned int j = cima + 1; j < N; j++)
    {
        if (arreglo[j] > arreglo[j - 1])
        {
            tiene_cima = false;
            break;
        }
    }
    if (cima == 0)
    {
        tiene_cima = false;
    }

    printf("El arreglo %s cima\n", tiene_cima ? "tiene" : "no tiene");
}