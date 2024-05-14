#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y)
{
    if (x >= 0)
    {
        *y = x;
    }
    else
    {
        *y = -x;
    }
}

int main(void)
{
    int a = 0, res = 0; // No modificar esta declaración

    a = -10;

    int *p = NULL;
    p = &res; // Asigna la dirección de memoria de res a p

    absolute(a, p);
    assert(res >= 0 && (res == a || res == -a));

    printf("Valor absoluto de %d: %d\n", a, res);

    return EXIT_SUCCESS;
}

/*
    ¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
    Tiene el tipo in/out
*/

/*
    ¿Qué tipo de parámetros tiene disponibles C para sus funciones?
    Parámetros in/out
*/
