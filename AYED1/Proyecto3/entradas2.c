#include <stdio.h>

int pedir_entero(char name, char var_almace) {
    int a;
    if (name == var_almace) {
        printf("Ingrese un valor para la variable %c: ", name);
        scanf("%d", &a);
    } else {
        printf("El valor se almacenará en la variable %c, no en %c\n", var_almace, name);
        printf("Ingrese un valor para la variable %c: ", name);
        scanf("%d", &a);
    }
    return a;
}

void imprimir_entero(char name, int x) {
    printf("El valor de la variable %c es: %d\n", name, x);
}

int main() {
    char var_almace = 'x'; // Aca se nombra donde se almacenara realmente la variable que se solicita

    int x = pedir_entero('n', var_almace); // En name se guarda el nombre de la variable a ingresar
    imprimir_entero('n', x);
    
    return 0;
}
//Ejemplos
// El valor se almacenará en la variable x, no en n
// Ingrese un valor para la variable n: 6
// El valor de la variable n es: 6