#include <stdio.h>

int pedir_entero(void)
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    return entero;
}

void imprimir_entero(int entero)
{
    printf("El numero que ingreso es: %d\n", entero);
}

int main(void)
{
    int entero;
    entero = pedir_entero();
    imprimir_entero(entero);
}