#include <stdio.h>
#include <assert.h>

void hola_hasta(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Hola\n");
    }
}

int pedir_entero(void)
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    assert(entero > 0);
    return entero;
}

int main(void)
{
    int repeticiones;
    repeticiones = pedir_entero();
    hola_hasta(repeticiones);

    return 0;
}