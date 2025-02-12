#include <stdio.h>
#include <assert.h>

typedef struct
{
    int cociente;
    int resto;
} div_t;

div_t division(int dividendo, int divisor)
{
    div_t mi_par;

    mi_par.cociente = (dividendo / divisor);
    mi_par.resto = (dividendo % divisor);

    return mi_par;
}

int main(void)
{
    int divisor, dividendo;
    div_t resultado;

    printf("Ingrese un Dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingrese un Divisor: ");
    scanf("%d", &divisor);
    assert(divisor != 0);

    resultado = division(dividendo, divisor);

    printf("El resultado de dividir %d por %d es %d con resto %d.\n", dividendo, divisor, resultado.cociente, resultado.resto);

    return 0;
}