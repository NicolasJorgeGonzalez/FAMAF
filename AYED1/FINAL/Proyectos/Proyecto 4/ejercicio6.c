#include <stdio.h>

void pedir_arreglo(int n_max, int a[]){
  int i = 0;

  while (i < n_max){
    int valor;
    printf("Ingrese un valor para el elemento en la posicion %d: ", (i +1));
    scanf("%d", &valor);
    a[i] = valor;
    i += 1;
  }
}

void imprimir_arreglo(int n_max, int a[]){
  int i,x;
  i = 0;

  while (i < n_max){
    x = a[i];
    printf("El valor en la posicion %d es: %d\n", i, x);
    i += 1;
  }
}

int main(void){
  int max_arreglo;

  printf("Ingrese un tamaño para el arreglo: ");
  scanf("%d", &max_arreglo);

  int arreglo[max_arreglo];

  pedir_arreglo(max_arreglo, arreglo);
  imprimir_arreglo(max_arreglo, arreglo);

  return 0;
}