#include <stdio.h>
#include <stdbool.h>

typedef char clave_t;
typedef int valor_t;

typedef struct
{
    clave_t clave;
    valor_t valor;
} asoc;

bool asoc_existe(int tam, asoc a[], clave_t c)
{
    int i = 0;
    bool resultado = false;

    while (i < tam)
    {
        resultado = resultado || c == a[i].clave;
        i++;
    }
    return resultado;
}

int main(void)
{
    int arreglo_tam, i = 0;
    char clave_objetivo;

    printf("Ingrese un tamaño para su arreglo: ");
    scanf("%d", &arreglo_tam);

    asoc arreglo[arreglo_tam];

    while (i < arreglo_tam)
    {
        char clave;
        int valor;

        printf("Ingrese una clave para el elemento %d: ", (i + 1));
        scanf(" %c", &clave); // Se agrega un espacio antes de %c para ignorar espacios en blanco

        printf("Ingrese un valor para el elemento %d: ", i + 1);
        scanf("%d", &valor);

        arreglo[i].clave = clave;
        arreglo[i].valor = valor;
        i++;
    }

    printf("Ingrese una clave para encontrar en el arreglo: ");
    scanf(" %c", &clave_objetivo);

    printf("La clave %c %s\n", clave_objetivo, asoc_existe(arreglo_tam, arreglo, clave_objetivo) ? "existe en el arreglo" : "no existe en el arreglo");

    return 0;
}