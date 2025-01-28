#include <stdio.h>
#define N 2
#define M 2

int main(void)
{
    int arreglo1[N][M] = {{1, 2}, {2, 3}};
    int arreglo2[N][M] = {{1, 2}, {2, 3}};
    int suma = 0;

    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j < M; j++)
        {
            suma = suma + (arreglo1[i][j] + arreglo2[i][j]);
        }
    }

    printf("La suma es %d\n", suma);
}