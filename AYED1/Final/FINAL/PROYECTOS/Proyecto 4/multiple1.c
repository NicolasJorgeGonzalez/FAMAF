#include <stdio.h>

int main(void){
    int x,y,xaux;
    printf("Ingresar el valor de X: ");
    scanf("%d", &x);
    printf("Ingresar el valor de Y: ");
    scanf("%d", &y);
    
    xaux = x;
    x = x + 1;
    y = xaux + y;

    printf("El valor de X= %d y de Y= %d\n", x, y);
}