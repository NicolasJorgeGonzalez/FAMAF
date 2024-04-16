#include <stdio.h>

int prim_iguales(int tam, int a[])
{
    int i = 0;
    int cantidad_iguales = 0;

    while (i < tam)
    {
        if (a[i] == a[i + 1])
        {
            cantidad_iguales += 1;
        }
        else if (a[i] != a[i + 1])
        {
            cantidad_iguales += 1;
            break;
        }
        i++;
    }
    return cantidad_iguales;
}
int main(void)
{
    int arreglo_tam, i = 0;

    printf("Ingrese el tamaño de su lista: ");
    scanf("%d", &arreglo_tam);

    int arreglo[arreglo_tam];

    while (i < arreglo_tam)
    {
        int valor;
        printf("\nIngrese un numero para el elemento %d: ", i + 1);
        scanf("%d", &valor);
        arreglo[i] = valor;
        i++;
    }

    int primIguales;
    primIguales = prim_iguales(arreglo_tam, arreglo);
    printf("\nLa cantidad de elementos iguales al inicio de la lista es: %d\n", primIguales);

    return 0;
}