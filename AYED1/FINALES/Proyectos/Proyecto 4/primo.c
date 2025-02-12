#include <stdio.h>

int es_primo(int numero)
{
    int divisor = 2;
    while (divisor < numero)
    {
        if ((numero % divisor) == 0)
        {
            return 0;
        }
        else
        {
            divisor++;
        }
    }
    return 1;
}

int nesimo_primo(int N)
{
    int primo_enesimo, candidato = 2, cantidad_primos = 0;

    while (cantidad_primos < N)
    {
        if (es_primo(candidato))
        {
            primo_enesimo = candidato;
            cantidad_primos++;
        }
        candidato++;
    }
    return primo_enesimo;
}

int main(void)
{
    int N, resultado;

    printf("Ingrese cual n-esimo primo desea obtener: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        main();
    }

    resultado = nesimo_primo(N);
    printf("El primo numero %d es %d.\n", N, resultado);

    return 0;
}