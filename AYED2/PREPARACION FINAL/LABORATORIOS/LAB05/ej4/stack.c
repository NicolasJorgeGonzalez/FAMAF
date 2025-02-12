#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack
{
    stack_elem elem;
    stack next;
};

stack stack_empty()
{
    stack new_stack = NULL;
    return new_stack;
}

stack stack_push(stack s, stack_elem e)
{
    stack new_stack = malloc(sizeof(struct _s_stack));
    new_stack->elem = e;
    new_stack->next = s;
    s = new_stack;
    return s;
}

stack stack_pop(stack s)
{
    assert(s != NULL);
    stack aux = s;
    s = s->next;
    free(aux);
    return s;
}

unsigned int stack_size(stack s)
{
    stack aux = s;
    int size = 0;
    while (aux != NULL)
    {
        aux = aux->next;
        size++;
    }
    return size;
}

stack_elem stack_top(stack s)
{
    assert(s != NULL);
    return s->elem;
}

bool stack_is_empty(stack s)
{
    return (s == NULL);
}

stack_elem *stack_to_array(stack s)
{
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        unsigned int length = stack_size(s);
        stack aux = s;
        stack_elem *array= calloc(length, sizeof(stack_elem));

        for (unsigned int i = (length - 1); i > 0; i--)
        {
            array[i] = aux->elem;
            aux = aux->next; 
        }
        array[0] = aux->elem;
        return array;
    }
}

stack stack_destroy(stack s)
{
    while (s != NULL) {
        stack aux = s;
        s = s->next;
        free(aux);
    }
    return NULL;
}