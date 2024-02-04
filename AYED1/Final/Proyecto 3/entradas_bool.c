#include <stdio.h>
#include <stdbool.h>

bool pedir_booleano(void)
{
    int valor;
    bool valor2;

    printf("Ingrese un valor booleano: ");
    scanf("%d", &valor);

    valor2 = valor;
    return valor2;
}

void imprimir_booleano(bool valor)
{
    if (valor != 0)
    {
        printf("El valor de su booleano es: True\n");
    }
    else
    {
        printf("El valor de su booleano es: False\n");
    }

    //     printf("El valor de su booleano es: %s \n", valor != 0 ? "True" : "False");
}

int main(void)
{
    int resultado;
    resultado = pedir_booleano();
    imprimir_booleano(resultado);
    return 0;
}