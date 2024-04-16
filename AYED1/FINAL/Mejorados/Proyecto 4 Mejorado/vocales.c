#include <stdio.h>
#include <stdbool.h>

char pedir_char(void)
{
    char letra;
    printf("Ingrese una letra: ");
    scanf("%c", &letra);
    return letra;
}

bool es_vocal(char letra)
{
    int resultado_bool;
    bool resultado;

    if ((letra == 'A') || (letra == 'E') || (letra == 'I') || (letra == 'O') || (letra == 'U'))
    {
        resultado_bool = 1;
    }
    else if ((letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u'))
    {
        resultado_bool = 1;
    }
    else
    {
        resultado_bool = 0;
    }

    resultado = resultado_bool;
    return resultado;
}

int main(void)
{
    char letra;
    int resultado_bool;
    bool resultado;

    letra = pedir_char();
    resultado = es_vocal(letra);
    resultado_bool = resultado;

    printf("La letra ingresada %s", resultado_bool != 0 ? "es vocal.\n" : "no es vocal.\n");

    return 0;
}