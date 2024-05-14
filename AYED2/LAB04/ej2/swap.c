#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(void)
{
    int x = 6, y = 4;
    int *a = NULL, *b = NULL;

    a = &x;
    b = &y;

    printf("Valor de X = %d, Y = %d\n", x, y);
    swap(a, b);
    printf("Valor de X = %d, Y = %d\n", x, y);

    return EXIT_SUCCESS;
}