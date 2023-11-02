#include <stdio.h>
#include <assert.h>

int main(void){
    int x,y,z;
    int X,Y,Z;

    printf("Ingresar el valor de X: ");
    scanf("%d", &x);
    printf("Ingresar el valor de Y: ");
    scanf("%d", &y);
    printf("Ingresar el valor de Z: ");
    scanf("%d", &z);

    Z = x;
    X = y;
    Y = z;

    assert(X != x && Y != y && Z != z);
    printf("Los valores intercabiados son los siguentes X = %d, Y = %d, Z = %d\n",X,Y,Z);
    return 0;
}