#include <stdio.h>

void swap_pointer(int *p, int *q)
{
    int aux = *p;
    *p = *q;
    *q = aux;
}

int main(void)
{
    int x = 5;
    int y = 10;

    int *a = &x;
    int *b = &y;

    printf("a:%p\nb:%p\n", (void *)a, (void *)b);
    printf("a vale:%d\nb vale:%d\n", *a, *b);

    swap_pointer(a, b);

    printf("a:%p\nb:%p\n", (void *)a, (void *)b);
    printf("a vale:%d\nb vale:%d\n", *a, *b);
}