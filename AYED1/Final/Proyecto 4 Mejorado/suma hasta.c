#include <stdio.h>
#include <assert.h>

int pedir_entero(void)
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    assert(entero > 0);
    return entero;
}

int suma_hasta(int n)
{
    int resultado = 0, i = 0;

    while (i != (n + 1))
    {
        resultado += i;
        i++;
    }
    return resultado;
}

int main(void)
{
    int hasta, resultado;
    hasta = pedir_entero();
    resultado = suma_hasta(hasta);
    printf("El resultado de la suma de los primero naturales hasta %d es %d.\n", hasta, resultado);
    return 0;
}