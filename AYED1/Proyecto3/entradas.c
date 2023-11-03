#include <stdio.h>

int pedir_entero(void){
    int x;

    printf("Ingrese un Numero Entero: ");
    scanf("%d", &x);

    return x;
}

void imprimir_entero(int x){
    printf("El numero ingresado es: %d\n", x);
}

int main(void){
    imprimir_entero(pedir_entero());
    return 0;
}
//Ejemplo
// Ingrese un Numero Entero: 5
// El numero ingresado es: 5