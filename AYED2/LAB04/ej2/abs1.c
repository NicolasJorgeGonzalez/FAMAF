#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y)
{
    if (x >= 0)
    {
        y = x;
    }
    else
    {
        y = -x;
    }
}

int main(void)
{
    int a = 0, res = 0;
    a = -10;
    absolute(a, res);
    printf("Valor absoluto de %d: %d\n", a, res);
    return EXIT_SUCCESS;
}
