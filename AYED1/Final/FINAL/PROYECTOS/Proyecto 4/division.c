#include <stdio.h>
#include <assert.h>

typedef struct
{
  int cociente;
  int resto;
} div_t;

div_t division(int divisor, int dividendo)
{
  div_t mipar;

  mipar.cociente = dividendo / divisor;
  mipar.resto = divisor % divisor;

  return mipar;
}

int main(void)
{
  int divisor, dividendo;

  printf("Ingrese un Dividendo: ");
  scanf("%d", &dividendo);
  printf("Ingrese un Divisor: ");
  scanf("%d", &divisor);

  assert(divisor > 0 && dividendo >= 0);

  div_t solucion = division(divisor, dividendo);

  printf("El resto de su division es: %d y su cociente es: %d\n", solucion.resto, solucion.cociente);

  return 0;
}