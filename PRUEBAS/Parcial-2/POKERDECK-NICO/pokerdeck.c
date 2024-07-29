~ / FAMAF / PRUEBAS / Parcial - 2 / POKERDECK #include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "pokerdeck.h"

                                    struct s_pokerdck
{
    unsigned int size;
    struct s_node *first;
};

struct s_node
{
    cardnum_t num;
    cardsuit_t suit;
    struct s_node *nextcard;
};

typedef struct s_node *node_t;

// Auxiliar dump functions
static void dump_suit(cardsuit_t suit)
{
    printf("%s", suit == spades ? "♠️  " : suit == hearts ? "♥️  "
                                      : suit == diamonds ? "♦️  "
                                      : suit == clubs    ? "♣️  "
                                                         : "???");
}

static void dump_num(cardnum_t num)
{
    if (1 < num && num < 11)
    {
        printf("%-2d", num);
    }
    else
    {
        printf("%-2s", num == 1 ? "A" : num == 11 ? "J"
                                    : num == 12   ? "Q"
                                    : num == 13   ? "K"
                                                  : "???");
    }
}

// Representation invariant
static bool invrep(pokerdeck deck)
{
    bool valid = true;

    if (deck == NULL)
    {
        valid = false;
    }

    return valid;
}

// Creates a single node in dynamic memory with a given card
static node_t create_node(cardnum_t num, cardsuit_t suit)
{
    node_t newnode = NULL;
    newnode = malloc(sizeof(struct s_node));

    newnode->num = num;
    newnode->suit = suit;
    newnode->nextcard = NULL;

    assert(newnode != NULL);

    return newnode;
}

// Destroy a single node
static node_t destroy_node(node_t node)
{
    assert(node != NULL);
    // node->nextcard = destroy_node(node->nextcard);
    // node->nextcard = NULL;
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

// Public functions of the Abstract Data Type
pokerdeck pokerdeck_empty(void)
{
    pokerdeck my_pokerdeck = NULL;

    my_pokerdeck = malloc(sizeof(struct s_pokerdck));
    my_pokerdeck->size = 0;
    my_pokerdeck->first = NULL;

    assert((my_pokerdeck != NULL) && (pokerdeck_is_empty(my_pokerdeck)));

    return my_pokerdeck;
}

bool pokerdeck_is_empty(pokerdeck deck)
{
    assert(deck != NULL);

    if ((deck->first == NULL) && (deck->size == 0))
    {
        assert(deck != NULL);
        return true;
    }
    else
    {
        assert(deck != NULL);
        return false;
    }
}

pokerdeck pokerdeck_add(pokerdeck deck, cardnum_t num, cardsuit_t suit)
{
    assert(deck != NULL);

    node_t new_node = create_node(num, suit);
    node_t aux_node = deck->first;

    if (pokerdeck_is_empty(deck))
    {
        deck->first = new_node;
    }
    else
    {
        while (aux_node->nextcard != NULL)
        {
            aux_node = aux_node->nextcard;
        }
        aux_node->nextcard = new_node;
    }

    deck->size++;

    assert((deck != NULL) && (!pokerdeck_is_empty(deck)));

    return deck;
}

pokerdeck pokerdeck_push(pokerdeck deck, cardnum_t num, cardsuit_t suit)
{
    assert(invrep(deck));
    node_t newnode = create_node(num, suit);

    newnode->nextcard = deck->first;
    deck->first = newnode;
    deck->size++;

    assert(invrep(deck) && !pokerdeck_is_empty(deck));
    return deck;
}

pokerdeck pokerdeck_pop(pokerdeck deck, cardnum_t *popped_num, cardsuit_t *popped_suit)
{
    assert((invrep(deck)) && (!pokerdeck_is_empty(deck)));

    if (popped_num != NULL)
        *popped_num = deck->first->num;
    if (popped_suit != NULL)
        *popped_suit = deck->first->suit;

    deck->first = deck->first->nextcard;

    assert(invrep(deck));
    return deck;
}

unsigned int pokerdeck_length(pokerdeck deck)
{
    assert(invrep(deck));
    unsigned int length = deck->size;
    assert(invrep(deck) && ((pokerdeck_is_empty(deck)) == (length == 0)));
    return length;
}

pokerdeck pokerdeck_remove(pokerdeck deck, cardnum_t num, cardsuit_t suit)
{
    assert(invrep(deck));

    node_t aux_node = deck->first;

    while ((aux_node->nextcard->num != num) && (aux_node->nextcard->suit != suit))
    {
        aux_node = aux_node->nextcard;
    }
    aux_node->nextcard = aux_node->nextcard->nextcard;

    assert(invrep(deck));
    return deck;
}

unsigned int pokerdeck_count(pokerdeck deck, cardsuit_t suit)
{
    assert(invrep(deck));

    unsigned int count = 0u;
    node_t aux_node = deck->first;

    while (aux_node->nextcard != NULL)
    {
        if (aux_node->suit == suit)
        {
            count++;
        }
        aux_node = aux_node->nextcard;
    }
    if (aux_node->suit == suit)
    {
        count++;
    }

    assert((invrep(deck)) && (count <= pokerdeck_length(deck)));

    return count;
}

struct card *pokerdeck_to_array(pokerdeck deck)
{
    assert(invrep(deck));

    node_t p = NULL;
    struct card *result = NULL;
    unsigned int size, i;

    if (!pokerdeck_is_empty(deck))
    {
        size = pokerdeck_length(deck);
        result = calloc(size, sizeof(struct card));
        p = deck->first;
        i = size - 1;

        while (p->nextcard != NULL)
        {
            struct card elem;
            elem.num = p->num;
            elem.suit = p->suit;
            result[i] = elem;
            p = p->nextcard;
            --i;
        }
    }

    assert(pokerdeck_length(deck) == 0);

    return result;
}

void card_dump(cardnum_t num, cardsuit_t suit)
{
    printf("|");
    dump_num(num);
    printf(" ");
    dump_suit(suit);
    printf("|");
}

void pokerdeck_dump(pokerdeck deck)
{
    assert(invrep(deck));
    node_t node = deck->first;
    while (node != NULL)
    {
        card_dump(node->num, node->suit);
        printf(" ");
        node = node->nextcard;
    }
    printf("\n");
}

pokerdeck pokerdeck_destroy(pokerdeck deck)
{
    node_t aux = deck->first;

    if (deck->first != NULL)
    {
        while (aux != NULL)
        {
            aux = aux->nextcard;
            deck->first = destroy_node(deck->first);
            deck->first = aux;
        }
    }
    free(deck);
    deck = NULL;

    assert(deck == NULL);
    return deck;
}