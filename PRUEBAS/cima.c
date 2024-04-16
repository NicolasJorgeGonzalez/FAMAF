#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool hay_cima = true;
    int a[9];
    int i = 2;

    for (int i = 0; i < 9; i++)
    {
        printf("Ingrese un valor para el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    while (hay_cima && i < 9)
    {
        if (a[i - 1] <= a[i])
        {
            i++;
        }
        else
        {
            if (a[i] >= a[i + 1])
            {
                i++;
            }
            else
            {
                hay_cima = false;
            }
        }
    }

    printf("Hay cima? %s\n", hay_cima ? "Si" : "No");

    return 0;
}