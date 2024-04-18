#include <stdio.h>
#include <stdbool.h>
#define N 9

// int main(void)
// {
//     bool hay_cima = true;
//     int a[N];
//     int i = 2;

//     for (int i = 0; i < N; i++)
//     {
//         printf("Ingrese un valor para el elemento %d: ", i + 1);
//         scanf("%d", &a[i]);
//     }

//     while (hay_cima && i < N)
//     {
//         if ((a[i - 1] <= a[i]) || a[i] >= a[i + 1])
//         {
//             i++;
//         }
//         else
//         {
//             hay_cima = false;
//         }
//     }

//     printf("Hay cima? %s\n", hay_cima ? "Si" : "No");

//     return 0;
// }

int main(void)
{
    int a[N];

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese un valor para el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    int inicio = 0;
    int fin = N;

    // Mientras el inicio no sea mayor que el final
    while (inicio <= fin)
    {
        // Encuentra el punto medio del arreglo
        int medio = inicio + (fin - inicio) / 2;

        // Si el objetivo está en el medio, devuelve su posición
        if ((a[medio] >= a[medio - 1]) && (a[medio + 1] <= a[medio]))
        {
            return printf("La cima esta en %d\n", (medio + 1));
        }
        // Si el objetivo es menor que el valor en el medio, busca en la mitad izquierda
        if (a[medio] < a[medio + 1])
        {
            fin = medio - 1;
        }
        // Si el objetivo es mayor, busca en la mitad derecha
        else
        {
            inicio = medio + 1;
        }
    }
    // Si no se encontró el objetivo, devuelve -1
    return printf("No se encontró la cima");
}