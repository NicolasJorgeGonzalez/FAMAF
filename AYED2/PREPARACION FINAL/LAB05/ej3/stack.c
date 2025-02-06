#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s)
{
    return (s != NULL)
}

stack stack_empty()
{
    stack my_stack = malloc(sizeof(struct _s_stack));

    my_stack->elems = malloc(sizeof(stack_elem) * my_stack->capacity);
    my_stack->size = 0;
    my_stack->capacity = 0;
    
    return my_stack;
}

stack stack_push(stack s, stack_elem e)
{
    assert(invrep(s));

    if (s->size == s->capacity)
    {
        stack new_stack = malloc(sizeof(struct _s_stack));
        new_stack->capacity = s->capacity * 2;
        new_stack = realloc(new_stack, new_stack->capacity * (sizeof(stack_elem)));
        
    }
    
}

stack stack_pop(stack s);

unsigned int stack_size(stack s);

stack_elem stack_top(stack s);

bool stack_is_empty(stack s);

stack_elem *stack_to_array(stack s);

stack stack_destroy(stack s);
