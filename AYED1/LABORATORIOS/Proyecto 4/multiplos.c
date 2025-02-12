#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool todos_pares(int tam, int a[]) {
    int i = 0;
    bool res = true;

    while (i < tam) {
        res = res && ((a[i] % 2) == 0);
        i += 1;
    }

    return res;
}

bool existe_multiplo(int m, int tam, int a[]) {
    int i = 0;
    bool res = false;

    while (i < tam) {
        res = res || ((a[i] % m) == 0);
        i += 1;
    }
    return res;
}

int main(void) {
    int tam_arreglo, opcion, m;
    int i = 0;

    printf("Ingrese un tamaño para su arreglo: ");
    scanf("%d", &tam_arreglo);

    int arreglo[tam_arreglo];

    while (i < tam_arreglo) {
        int valor;
        printf("Ingrese un valor para el elemento en la posicion %d: ", (i + 1));
        scanf("%d", &valor);
        arreglo[i] = valor;
        i += 1;
    }

    system("clear");

    printf("1. Todos pares\n");
    printf("2. Existe multiplo\n");
    printf("Escoja una opcion: ");
    scanf("%d", &opcion);
    
    system("clear");

    switch (opcion){
        case 1:
            printf("El resultado de ejecutar la funcion es: %s\n", todos_pares(tam_arreglo, arreglo) ? "True" : "False");
            break;
        case 2:
            printf("De que numero desea buscar un multiplo? ");
            scanf("%d", &m);
            printf("El resultado de ejecutar la funcion es: %s\n", existe_multiplo(m, tam_arreglo, arreglo) ? "True" : "False");
            break;
    }

    return 0;
}
