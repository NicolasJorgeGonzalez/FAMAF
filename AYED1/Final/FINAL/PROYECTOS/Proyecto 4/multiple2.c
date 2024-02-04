#include <stdio.h>

int main(void){
    int x,y,z,xaux,yaux;
    printf("Ingresar el valor de X: ");
    scanf("%d", &x);
    printf("Ingresar el valor de Y: ");
    scanf("%d", &y);
    printf("Ingresar el valor de Z: ");
    scanf("%d", &z);

    xaux = x;
    yaux = y;
    x = y;
    y = xaux + y + z;
    z = yaux + xaux;

    printf("Los valores nuevos son X= %d Y= %d Z= %d\n", x, y, z);
}