#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./pair.h"

struct s_pair_t
{
    int fst;
    int snd;
};

pair_t pair_new(int x, int y)
{
    pair_t p = NULL;
    p = malloc(sizeof(x) + sizeof(y));
    p->fst = x;
    p->snd = y;

    return p;
}

int pair_first(pair_t p)
{
    return p->fst;
}

int pair_second(pair_t p)
{
    return p->snd;
}

pair_t pair_swapped(pair_t p)
{
    pair_t q = NULL;
    q = malloc(sizeof(p));
    q->fst = pair_second(p);
    q->snd = pair_first(p);

    return q;
}

pair_t pair_destroy(pair_t p)
{
    free(p);
    p = NULL;

    return p;
}