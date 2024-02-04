#include <stdio.h>

int sumatoria(int tam, int a[]){
  int i = 0;
  int sumatoria_arreglo = 0;

  while (i < tam){
    int valor;
    printf("Ingrese un valor para el elemento en la posicion %d: ", (i +1));
    scanf("%d", &valor);
    a[i] = valor;
    
    sumatoria_arreglo += valor;
    i += 1;
  }

  return sumatoria_arreglo;
}

int main(void){
  int tamano_arreglo, total;

  printf("Ingrese un tamaño para el arreglo: ");
  scanf("%d", &tamano_arreglo);

  int arreglo[tamano_arreglo];

  total = sumatoria(tamano_arreglo, arreglo);

  printf("La sumatoria de los elementos del su arreglo es: %d\n", total);

  return 0;
}