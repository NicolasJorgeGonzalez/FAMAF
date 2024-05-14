#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"
#define initial_value 0

struct _counter
{
    unsigned int count;
};

counter counter_init(void)
{
    counter c = NULL;
    c = malloc(sizeof(unsigned int));
    c->count = initial_value;

    return c;
}

void counter_inc(counter c)
{
    c->count = c->count + 1;
}

bool counter_is_init(counter c)
{
    return (c->count == initial_value);
}

void counter_dec(counter c)
{
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c)
{
    counter p = NULL;
    p = malloc(sizeof(unsigned int));
    p->count = c->count;

    return p;
}

void counter_destroy(counter c)
{
    free(c);
    c = NULL;
}
