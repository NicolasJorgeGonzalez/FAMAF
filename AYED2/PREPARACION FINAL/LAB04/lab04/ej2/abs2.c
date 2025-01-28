#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y)
{
    if (x < 0)
    {
        *y = x * (-1);
    }
    else
    {
        *y = x;
    }
}

int main(void)
{
    int a = (-10), res = 0;
    int *p = NULL;

    p = &res;

    absolute(a, p);

    printf("El valor absoluto de %d es %d\n", a, *p);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}
