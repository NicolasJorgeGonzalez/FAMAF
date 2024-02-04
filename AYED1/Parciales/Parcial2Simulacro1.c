#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// int pedir_entero(void)
// {
//     int x;

//     printf("Ingrese un Numero Entero: ");
//     scanf("%d", &x);

//     return x;
// }

// void imprimir_entero(char variable, int valor)
// {
//     printf("El valor de %c es: %d\n", variable, valor);
// }

// bool pedir_bool(void)
// {
//     int x;
//     bool temp;

//     printf("Ingrese un Bool: ");
//     scanf("%d", &x);

//     temp = x;

//     return temp;
// }

// void imprimir_bool(char variable, bool temp)
// {
//     printf("El valor de %c es: %s\n", variable, temp ? "True" : "False");
// }

// int main(void)
// {
//     int x, y;
//     bool z;

//     x = pedir_entero();
//     y = pedir_entero();
//     z = pedir_bool();

//     int X = x, Y = y;
//     bool Z = z;

//     assert(x == X && y == Y && z == Z);

//     x = X * X + Y * Y;
//     y = X % Y;
//     z = X < Y;

//     assert((x == X * X + Y * Y) && (y == X % Y) && (z == (X < Y)));

//     imprimir_entero('x', x);
//     imprimir_entero('y', y);
//     imprimir_bool('z', z);
// }

// EJERCICIO 2

#include <limits.h>

// int maximo_negativo(int a[], int tam)
// {
//     int i = 0, maximo = INT_MIN;
//     while (i < tam)
//     {
//         if ((a[i] > maximo) && (a[i] < 0))
//         {
//             maximo = a[i];
//         }
//         else
//         {
//             i++;
//         }
//     }

//     if (maximo == INT_MIN)
//     {
//         maximo = INT_MAX;
//     }

//     return maximo;
// }

// int main(void)
// {
//     int N = 5, i = 0, resultado;
//     int arreglo[N];

//     while (i < N)
//     {
//         int valor;
//         printf("Ingresar una valor para el elemento en la posicion %d: ", i + 1);
//         scanf("%d", &valor);
//         arreglo[i] = valor;
//         i++;
//     }

//     resultado = maximo_negativo(arreglo, N);
//     printf("El maximo negativo del arreglo es: %d\n", resultado);
// }

// EJERCICIO 3

// typedef struct
// {
//     int minimo;
//     int indice_min;
//     int maximo;
//     int indice_max;
// } maxmin_t;

// maxmin_t cotas(int a[], int tam)
// {
//     int i = 0;
//     maxmin_t resultados;
//     resultados.maximo = INT_MIN;
//     resultados.minimo = INT_MAX;

//     while (i < tam)
//     {
//         if (a[i] > resultados.maximo)
//         {
//             resultados.maximo = a[i];
//             resultados.indice_max = i;
//         }
//         else if (a[i] < resultados.minimo)
//         {
//             resultados.minimo = a[i];
//             resultados.indice_min = i;
//         }
//         i++;
//     }
//     return resultados;
// }

// int main(void)
// {
//     int N = 5, i = 0;
//     maxmin_t resultado;

//     int arreglo[N];

//     while (i < N)
//     {
//         int valor;
//         printf("Ingresar una valor para el elemento en la posicion %d: ", i + 1);
//         scanf("%d", &valor);
//         arreglo[i] = valor;
//         i++;
//     }

//     resultado = cotas(arreglo, N);
//     printf("Minimo: %d\nIndice Minimo:%d\n Maximo:%d\nIndice Maximo: %d\n", resultado.minimo, resultado.indice_min, resultado.maximo, resultado.indice_max);
// }

// EJERCICIO 4

// typedef struct
// {
//     int dni;
//     int altura;
// } persona;

// typedef struct
// {
//     int n_bajos;
//     int n_altos;
// } alturas_t;

// alturas_t contar_altos_y_bajos(persona a[], int tam, float alt)
// {
//     int i = 0;
//     alturas_t resultados;
//     resultados.n_bajos = 0;
//     resultados.n_altos = 0;

//     while (i < tam)
//     {
//         if (a[i].altura < alt)
//         {
//             resultados.n_bajos++;
//         }
//         else
//         {
//             resultados.n_altos++;
//         }
//         i++;
//     }
//     return resultados;
// }

// int main(void)
// {
//     int N = 5, i = 0;
//     float altura_objetivo;

//     persona arreglo[N];

//     while (i < N)
//     {
//         printf("DNI de la persona %d: ", i + 1);
//         scanf("%d", &arreglo[i].dni);
//         printf("Altura de la persona %d: ", i + 1);
//         scanf("%d", &arreglo[i].altura);
//         i++;
//     }

//     printf("Ingrese una altura objetivo: ");
//     scanf("%f", &altura_objetivo);

//     alturas_t resultados = contar_altos_y_bajos(arreglo, N, altura_objetivo);
//     printf("La cantidad de bajos es %d y la cantidad de altos es %d.\n", resultados.n_bajos, resultados.n_altos);
// }