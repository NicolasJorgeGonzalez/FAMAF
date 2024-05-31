#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    stack_elem element;
    stack next;
};

stack stack_empty()
{
    stack my_stack = NULL;

    return my_stack;
}

stack stack_push(stack s, stack_elem e)
{
    stack my_stack = NULL;
    my_stack = malloc(sizeof(stack_elem));
    my_stack->element = e;
    my_stack->next = s;

    return my_stack;
}

stack stack_pop(stack s)
{
    assert(s != NULL);
    stack my_stack = NULL;
    my_stack = malloc(sizeof(stack_elem));
    my_stack = s->next;

    return my_stack;
}

unsigned int stack_size(stack s)
{
    unsigned int length = 0u;
    stack my_stack_aux = s;
    while (my_stack_aux != NULL)
    {
        length++;
        my_stack_aux = my_stack_aux->next;
    }

    return length;
}

stack_elem stack_top(stack s)
{
    assert(s != NULL);

    return s->element;
}

bool stack_is_empty(stack s)
{
    if (s == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

stack_elem *stack_to_array(stack s)
{
    stack my_stack = s;
    stack_elem *array;
    unsigned int length = stack_size(s);
    array = (stack_elem *)calloc(length, sizeof(stack_elem));

    for (unsigned int i = 0u; i < length; i++)
    {
        array[i] = my_stack->element;
        my_stack = my_stack->next;
    }

    return array;
}

stack stack_destroy(stack s)
{
    free(s);
    s = NULL;

    return s;
}