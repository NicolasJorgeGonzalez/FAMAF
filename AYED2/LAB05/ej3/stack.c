#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define INITIAL_CAPACITY

struct _s_stack
{
    stack_elem *elems;     // Arreglo de elementos
    unsigned int size;     // Cantidad de elementos en la pila
    unsigned int capacity; // Capacidad actual del arreglo elems
};

bool invrep(stack s)
{
    return s != NULL;
}

stack stack_empty()
{
    stack my_stack = (stack)malloc(sizeof(struct _s_stack));
    my_stack->elems = (stack_elem *)malloc(INITIAL_CAPACITY * sizeof(stack_elem));
    my_stack->size = 0;
    my_stack->capacity = INITIAL_CAPACITY;
}

stack stack_push(stack s, stack_elem e)
{
    assert(invrep(s));

    if (s->size == s->capacity)
    {
        unsigned int new_capacity = s->capacity * 2;
        stack_elem *new_elems = (stack_elem *)realloc(s->elems, new_capacity * sizeof(stack_elem));

        s->elems = new_elems;
        s->capacity = new_capacity;
    }

    s->elems[s->size] = e;
    s->size++;

    assert(invrep(s) && !stack_is_empty(s));
    return s;
}