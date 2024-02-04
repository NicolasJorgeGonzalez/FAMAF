#include <stdio.h>
#include <stdbool.h>

bool pedir_bool(void){
    int x;
    bool temp;

    printf("Ingrese un Bool: ");
    scanf("%d", &x);

    temp = x;

    return temp;
}

void imprimir_bool(bool temp){
    printf("El Bool ingresado es: %s\n", temp ? "True" : "False");
}

int main(void){
    imprimir_bool(pedir_bool());
    return 0;
}
//Ejemplos
// Ingrese un Bool: 4
// El Bool ingresado es: True