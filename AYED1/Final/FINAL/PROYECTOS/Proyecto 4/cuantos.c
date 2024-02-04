#include <stdio.h>

typedef struct
{
    int menores;
    int iguales;
    int mayores;
} comp_t;

comp_t cuantos(int tam, int a[], int elem)
{
    int i = 0;

    comp_t todos;
    todos.iguales = 0;
    todos.mayores = 0;
    todos.menores = 0;

    while (i < tam)
    {
        if (a[i] == elem)
        {
            todos.iguales += 1;
        }
        else if (a[i] > elem)
        {
            todos.mayores += 1;
        }
        else if (a[i] < elem)
        {
            todos.menores += 1;
        }
        i++;
    }

    return todos;
}

int main(void)
{
    int arreglo_tam, objetivo, i = 0;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &arreglo_tam);
    printf("Ingrese que valor desea buscar en el arreglo: ");
    scanf("%d", &objetivo);

    int arreglo[arreglo_tam];

    while (i < arreglo_tam)
    {
        int valor;
        printf("Ingrese un valor para el elemento %d del arreglo: ", i + 1);
        scanf("%d", &valor);
        arreglo[i] = valor;
        i++;
    }

    comp_t resultados = cuantos(arreglo_tam, arreglo, objetivo);

    printf("Cantidad de menores: %d\n", resultados.menores);
    printf("Cantidad de iguales: %d\n", resultados.iguales);
    printf("Cantidad de mayores: %d\n", resultados.mayores);

    return 0;
}