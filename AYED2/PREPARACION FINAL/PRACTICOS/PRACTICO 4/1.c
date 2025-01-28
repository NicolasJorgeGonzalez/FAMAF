#include <stdio.h>
#define N

int main(void)
{
    int arreglo[N][N] = {};

    int min = arreglo[0][0];

    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j < N; j++)
        {
            if (arreglo[i][j] < min)
            {
                min = arreglo[i][j];
            }
        }
    }

    printf("El menor elemento del arreglo es %d\n", min);
    return 0;
}
