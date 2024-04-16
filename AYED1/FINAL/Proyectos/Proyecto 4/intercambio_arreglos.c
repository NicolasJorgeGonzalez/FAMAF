#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void imprimir_arreglo(int n_max, int a[])
{
  int i, x;
  i = 0;

  while (i < n_max)
  {
    x = a[i];
    printf("El valor en la posicion %d es: %d\n", i, x);
    i += 1;
  }
}

void intercambiar(int a[], int i, int j)
{
  int x, y;
  x = a[i];
  y = a[j];
  a[i] = y;
  a[j] = x;
}

int main(void)
{
  int tam_arreglo, x, y, i = 0;

  printf("Ingrese un tamaño para el arreglo: ");
  scanf("%d", &tam_arreglo);

  system("clear");

  int arreglo[tam_arreglo];

  while (i < tam_arreglo)
  {
    int valor;
    printf("Ingrese un valor para el elemento en la posicion %d: ", (i + 1));
    scanf("%d", &valor);
    arreglo[i] = valor;
    i++;
  }

  system("clear");

  imprimir_arreglo(tam_arreglo, arreglo);

  printf("Cual es la posicion del elemento que desea intercambiar? ");
  scanf("%d", &x);
  printf("Con cual posicion desea intercambiar? ");
  scanf("%d", &y);

  assert((0 <= x && x < tam_arreglo) && (0 <= y && y < tam_arreglo));

  system("clear");

  intercambiar(arreglo, x, y);

  imprimir_arreglo(tam_arreglo, arreglo);

  return 0;
}