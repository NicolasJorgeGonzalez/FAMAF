#include <stdio.h>
#include <assert.h>

int es_vocal(char letra){
    int x;
    if (letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u'){
        x = 1;
    }
    else{
        x = 0;
    }

    printf("La letra ingresada: %s\n", (x == 1) ? "Es vocal" : "No es vocal");
    return 0;
}


int main(void){
    char x;
    printf("Ingrese una letra: ");
    scanf("%c", &x);

    es_vocal(x);
    return 0;
}