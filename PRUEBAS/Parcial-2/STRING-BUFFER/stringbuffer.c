#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "stringbuffer.h"

struct s_stringbuffer
{
    struct s_node *first;
    struct s_node *last;
    unsigned int size;
};

struct s_node
{
    char c;
    struct s_node *nextchar;
};

typedef struct s_node *node_t;

// Representation invariant
static bool invrep(stringbuffer sb)
{
    bool valid = false;
    if (sb != NULL)
    {
        return true;
    }

    return valid;
}

// Creates a single node in dynamic memory with a given char
static node_t create_node(char c)
{
    node_t newnode = NULL;

    newnode = malloc(sizeof(struct s_node));
    newnode->c = c;
    newnode->nextchar = NULL;

    assert(newnode != NULL);
    return newnode;
}

// Destroy a single node
static node_t destroy_node(node_t node)
{
    free(node);
    node = NULL;

    assert(node == NULL);
    return node;
}

// Public functions of the Abstract Data Type
stringbuffer stringbuffer_empty(void)
{
    stringbuffer my_stringbuffer = NULL;
    my_stringbuffer = malloc(sizeof(struct s_stringbuffer));

    my_stringbuffer->first = NULL;
    my_stringbuffer->last = NULL;
    my_stringbuffer->size = 0u;

    assert(invrep(my_stringbuffer) && stringbuffer_is_empty(my_stringbuffer));
    return my_stringbuffer;
}

stringbuffer stringbuffer_create(const char *word)
{
    assert(word != NULL);
    stringbuffer sb = stringbuffer_empty();
    for (unsigned int i = 0; word[i] != '\0'; i++)
    {
        sb = stringbuffer_append(sb, word[i]);
    }
    assert(invrep(sb) && !stringbuffer_is_empty(sb));
    return sb;
}

bool stringbuffer_is_empty(stringbuffer sb)
{
    assert(invrep(sb));
    if ((sb->size == 0) && (sb->first == NULL) && (sb->last == NULL))
    {
        assert(invrep(sb));
        return true;
    }
    else
    {
        assert(invrep(sb));
        return false;
    }
}

stringbuffer stringbuffer_append(stringbuffer sb, const char c)
{
    assert(invrep(sb));
    node_t new_node = create_node(c);

    if (sb->first == NULL)
    {
        sb->first = new_node;
        sb->last = new_node;
    }
    else
    {
        sb->last->nextchar = new_node;
        sb->last = new_node;
    }
    sb->size++;

    assert(invrep(sb));
    return sb;
}

char stringbuffer_char_at(stringbuffer sb, unsigned int index)
{
    assert(invrep(sb) && !stringbuffer_is_empty(sb) && index < stringbuffer_length(sb));
    unsigned pos = 0;
    node_t node = sb->first;
    while (pos < index)
    {
        node = node->nextchar;
        pos++;
    }

    assert(invrep(sb));
    return node->c;
}

stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index)
{
    assert(invrep(sb));
    node_t node = sb->first;
    node_t previus = NULL;
    unsigned pos = 0;

    while (node != NULL)
    {
        if (pos == index)
        {
            previus = node->nextchar;
            sb->size--;
            assert(invrep(sb));
            return sb;
        }
        previus = node;
        node = node->nextchar;
        pos++;
    }
    destroy_node(node);
    destroy_node(previus);

    assert(invrep(sb));
    return sb;
}

stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index)
{
    assert(invrep(sb) && (index < stringbuffer_length(sb)));

    node_t new_node = create_node(c), aux = sb->first;
    unsigned int pos = 0u;

    while (aux != NULL)
    {
        if (pos == index)
        {
            aux->c = c;
            assert(invrep(sb));
            return sb;
        }
        aux = aux->nextchar;
        pos++;
    }
    destroy_node(new_node);
    destroy_node(aux); // Es al pedo??

    assert(invrep(sb));
    return sb;
}

unsigned int stringbuffer_length(stringbuffer sb)
{
    assert(invrep(sb));
    unsigned int length = sb->size;
    assert(invrep(sb) && (stringbuffer_is_empty(sb) == (length == 0)));
    return length;
}

char *stringbuffer_to_string(stringbuffer sb)
{
    assert(invrep(sb));

    node_t node = NULL;
    char *array = NULL;
    unsigned int length, i;

    if (!stringbuffer_is_empty(sb))
    {
        length = stringbuffer_length(sb);
        array = calloc(length, sizeof(char));
        node = sb->first;
        i = length - 1;

        while (node->nextchar != NULL)
        {
            array[i] = node->c;
            node = node->nextchar;
            i--;
        }
    }

    return array;
}

void stringbuffer_dump(stringbuffer sb)
{
    assert(invrep(sb));
    node_t node = sb->first;
    while (node != NULL)
    {
        printf("%c", node->c);
        node = node->nextchar;
    }
    destroy_node(node);
    printf("\n");
}

stringbuffer stringbuffer_destroy(stringbuffer sb)
{
    node_t aux = sb->first;

    if (sb->first != NULL)
    {
        while (aux != NULL)
        {
            aux = aux->nextchar;
            sb->first = destroy_node(sb->first);
            sb->first = aux;
        }
    }
    free(aux);
    aux = NULL;
    free(sb);
    sb = NULL;

    assert(sb == NULL);
    return sb;
}
