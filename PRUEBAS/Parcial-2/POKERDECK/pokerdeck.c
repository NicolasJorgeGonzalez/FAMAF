#include <stdlib.h>
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
    bool valid = false;

    if (deck != NULL)
    {
        valid = true;
    }

    return valid;
}

// Creates a single node in dynamic memory with a given card
static node_t create_node(cardnum_t num, cardsuit_t suit)
{
    node_t newnode = malloc(sizeof(struct s_node));

    newnode->num = num;
    newnode->suit = suit;
    newnode->nextcard = NULL;

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
pokerdeck pokerdeck_empty(void)
{
    pokerdeck my_pokerdeck = NULL;
    my_pokerdeck = malloc(sizeof(struct s_pokerdck));
    my_pokerdeck->size = 0;
    my_pokerdeck->first = NULL;
    assert((invrep(my_pokerdeck)) && (pokerdeck_is_empty(my_pokerdeck)));

    return my_pokerdeck;
}

bool pokerdeck_is_empty(pokerdeck deck)
{
    assert(invrep(deck));
    if ((deck->first == NULL) && (deck->size == 0))
    {
        assert(invrep(deck));
        return true;
    }
    else
    {
        assert(invrep(deck));
        return false;
    }
}

pokerdeck pokerdeck_add(pokerdeck deck, cardnum_t num, cardsuit_t suit)
{
    assert(invrep(deck));
    node_t newnode = create_node(num, suit);
    node_t last = deck->first;

    if (last == NULL)
    {
        deck->first = newnode;
    }
    else
    {
        while (last->nextcard != NULL)
        {
            last = last->nextcard;
        }
        last->nextcard = newnode;
    }
    deck->size = deck->size + 1;
    destroy_node(last);
    destroy_node(newnode);
    assert(invrep(deck) && !pokerdeck_is_empty(deck));

    return deck;
}

pokerdeck pokerdeck_push(pokerdeck deck, cardnum_t num, cardsuit_t suit)
{
    assert(invrep(deck));
    node_t newnode = create_node(num, suit);

    newnode->nextcard = deck->first;
    deck->first = newnode;
    deck->size = deck->size + 1;
    destroy_node(newnode);
    assert(invrep(deck) && !pokerdeck_is_empty(deck));

    return deck;
}

pokerdeck pokerdeck_pop(pokerdeck deck, cardnum_t *popped_num, cardsuit_t *popped_suit)
{
    assert(invrep(deck) && !pokerdeck_is_empty(deck));
    node_t new_node = deck->first;

    if (popped_num != NULL)
        *popped_num = new_node->num;
    if (popped_suit != NULL)
        *popped_suit = new_node->suit;
    deck->first = new_node->nextcard;
    deck->size = deck->size - 1;
    destroy_node(new_node);
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
    node_t newnode = deck->first;
    node_t previous = NULL;

    while (newnode != NULL)
    {
        if ((newnode->num == num) && (newnode->suit == suit))
        {
            if (previous == NULL)
            {
                deck->first = newnode->nextcard;
            }
            else
            {
                previous->nextcard = newnode->nextcard;
            }
            deck->size = deck->size - 1;
            destroy_node(newnode);
            break;
        }
        previous = newnode;
        newnode = newnode->nextcard;
    }
    destroy_node(newnode);
    destroy_node(previous);
    assert(invrep(deck));

    return deck;
}

unsigned int pokerdeck_count(pokerdeck deck, cardsuit_t suit)
{
    assert(invrep(deck));
    node_t newnode = deck->first;
    unsigned int count = 0u;

    while (newnode != NULL)
    {
        if (newnode->suit == suit)
        {
            count++;
        }
        newnode = newnode->nextcard;
    }
    destroy_node(newnode);
    assert(invrep(deck) && (count <= pokerdeck_length(deck)));

    return count;
}

struct card *pokerdeck_to_array(pokerdeck deck)
{
    assert(invrep(deck));
    struct card *array = malloc(sizeof(struct card) * deck->size);
    node_t newnode = deck->first;
    unsigned int i = 0u;

    while (newnode != NULL)
    {
        array[i].num = newnode->num;
        array[i].suit = newnode->suit;
        newnode = newnode->nextcard;
        i++;
    }
    destroy_node(newnode);
    assert((pokerdeck_length(deck) == 0) == (array == NULL));

    return array;
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
    free(deck);
    deck = NULL;

    return deck;
}
