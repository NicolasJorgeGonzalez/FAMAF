#include <stdio.h>
#include <stdbool.h>

int pedir_bool(char name, char var_almc){
    int temp;
    bool b;

    if(name == var_almc){

        printf("Ingrese un valor Boleano denominado '%c' almacenado en %c: ", name, var_almc);
        scanf("%d", &temp);
        b = temp;
    }else{

        printf("Ingrese un valor Boleano denominado '%c' que será almacenado en %c, no en %c: ", name, var_almc, name);
        scanf("%d", &temp);
        b = temp;        
    }
    return b;

}
void imprimir_bool(char name, int a){


    printf("EL Booleano denomido '%c' es: %s\n", name, a ? "True" : "False");
}

int main(void){

    char var_alc = 'x'; // Aca se nombra donde se almacenara realmente la variable que se solicita
    bool x, n;
    
    x = pedir_bool('n', var_alc); // En name se guarda el nombre de la variable a ingresar
    imprimir_bool ('n', x);

    var_alc = 'n';

    n = pedir_bool('n', var_alc);
    imprimir_bool('n', n);

    return 0;
}
//Ejemplos
// Ingrese un valor Boleano denominado 'n' que será almacenado en x, no en n: 5
// EL Booleano denomido 'n' es: True
// Ingrese un valor Boleano denominado 'n' almacenado en n: 2
// EL Booleano denomido 'n' es: True