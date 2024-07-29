#include <stdio.h>
#include <stdlib.h>
#include "walk.h"
#include <assert.h>

#define STEP_NORTH 0
#define STEP_EAST 1
#define STEP_NORTHEAST 2
#define STEP_UNDEF 3

typedef unsigned int step_t;
typedef unsigned int uint_t;

struct _node_t
{
    step_t step;
    struct _node_t *next;
};

typedef struct _node_t *node_t;

struct _walk_t
{
    node_t init;
    node_t last;
    uint_t length;
    uint_t width;
    uint_t height;
};

walk_t walk_empty(void)
{
    walk_t walk = NULL;
    walk = malloc(sizeof(struct _walk_t));

    walk->init = NULL;
    walk->last = NULL;
    walk->length = 0;
    walk->width = 0;
    walk->height = 0;

    assert((walk != NULL) && (walk_length(walk) == 0));
    return walk;
}

static node_t create_node(void)
{
    node_t node = NULL;
    node = malloc(sizeof(struct _node_t));
    node->step = STEP_UNDEF;
    node->next = NULL;

    assert(node != NULL);
    return node;
}

static node_t destroy_node(node_t node)
{
    assert(node != NULL);

    free(node);
    node = NULL;

    assert(node == NULL);
    return node;
}

walk_t walk_north(walk_t walk)
{
    assert(walk != NULL);

    node_t node = create_node();
    node->step = STEP_NORTH;
    if (walk_length(walk) == 0)
    {
        walk->init = node;
        walk->last = walk->init;
    }
    else
    {
        walk->last->next = node;
    }
    walk->length++;
    walk->height++;

    assert((walk != NULL) && (walk_length(walk) > 0));
    return walk;
}

walk_t walk_east(walk_t walk)
{
    assert(walk != NULL);

    node_t node = create_node();
    node->step = STEP_EAST;
    if (walk_length(walk) == 0)
    {
        walk->init = node;
        walk->last = walk->init;
    }
    else
    {
        walk->last->next = node;
    }
    walk->length++;
    walk->width++;

    assert((walk != NULL) && (walk_length(walk) > 0));
    return walk;
}

walk_t walk_northeast(walk_t walk)
{
    assert(walk != NULL);

    node_t node = create_node();
    node->step = STEP_NORTHEAST;
    if (walk_length(walk) == 0)
    {
        walk->init = node;
        walk->last = walk->init;
    }
    else
    {
        walk->last->next = node;
    }
    walk->length++;
    walk->width++;
    walk->height++;

    assert((walk != NULL) && (walk_length(walk) > 0));
    return walk;
}

unsigned int walk_length(walk_t walk)
{
    assert(walk != NULL);
    unsigned int length = walk->length;
    assert(walk != NULL);
    return length;
}

unsigned int walk_height(walk_t walk)
{
    assert(walk != NULL);
    unsigned int height = walk->height;
    assert(walk != NULL);
    return height;
}

unsigned int walk_width(walk_t walk)
{
    assert(walk != NULL);
    unsigned int width = walk->width;
    assert(walk != NULL);
    return width;
}

walk_t walk_extend(walk_t walk, unsigned int east, unsigned int north)
{
    assert(walk != NULL);

    for (unsigned int i = 0u; i < east; i++)
    {
        walk_east(walk);
    }
    for (unsigned int j = 0u; j < north; j++)
    {
        walk_north(walk);
    }

    assert((walk != NULL) && (walk_length(walk) > 0 || (east == 0 && north == 0)));
    return walk;
}

static char step_to_char(step_t step)
{
    char c = '\0';
    switch (step)
    {
    case STEP_NORTH:
        c = 'N';
        break;
    case STEP_EAST:
        c = 'E';
        break;
    case STEP_NORTHEAST:
        c = 'X';
        break;
    default:
        c = 'U';
        break;
    }
    return c;
}

void walk_dump(walk_t walk)
{
    assert(walk != NULL);

    node_t aux = walk->init;
    printf("[");
    while (aux != NULL)
    {
        printf("%c", step_to_char(aux->step));
        if (aux->next != NULL)
        {
            printf(" -> ");
        }
        aux = aux->next;
    }
    printf("] (L=%u,W=%u,H=%u)\n", walk->length, walk->width, walk->height);
}

walk_t walk_destroy(walk_t walk)
{
    assert(walk != NULL);

    node_t aux = walk->init;
    while (aux != NULL)
    {
        node_t next = aux->next;
        destroy_node(aux);
        aux = next;
    }
    free(walk);
    walk = NULL;

    assert(walk == NULL);
    return walk;
}
