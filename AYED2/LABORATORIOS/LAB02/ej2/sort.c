#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
    int ppiv;
    if (der > izq)
    {
        ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0) ? 0 : ppiv - 1);
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length)
{
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
