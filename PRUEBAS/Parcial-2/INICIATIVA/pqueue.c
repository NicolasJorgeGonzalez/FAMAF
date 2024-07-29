#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "character/character.h"
#include "pqueue.h"

/* ============================================================================
STRUCTS!
============================================================================ */

typedef struct s_node *node_t;

struct s_node
{
  Character character;
  float iniciative;
  node_t next;
};

struct s_pqueue
{
  node_t first;
  unsigned int size;
};

/* ============================================================================
INVREP
============================================================================ */

static bool invrep(pqueue q)
{
  if (q == NULL)
  {
    return false;
  }
  if (q->size == 0 && q->first != NULL)
  {
    return false;
  }
  if (q->size != 0 && q->first == NULL)
  {
    return false;
  }
  return true;
}

/* ============================================================================
NEW
============================================================================ */

pqueue pqueue_empty(void)
{
  pqueue q = NULL;
  q = malloc(sizeof(struct s_pqueue));
  q->first = NULL;
  q->size = 0;

  assert(invrep(q) && pqueue_is_empty(q));
  return q;
}

/* ============================================================================
ENQUEUE
============================================================================ */

static float calculate_priority(Character character)
{
  unsigned int agility = character_agility(character);
  charttype_t type = character_ctype(character);
  bool is_alive = character_is_alive(character);

  float modify;
  if (type == agile)
  {
    modify = 1.5;
  }
  else if (type == tank)
  {
    modify = 0.8;
  }

  float priority = agility * (is_alive ? 0 : 1) * modify;

  return priority;
}

node_t create_node(Character character)
{
  struct s_node *new_node = NULL;
  float priority = calculate_priority(character);
  new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  new_node->character = character;
  new_node->iniciative = priority;
  new_node->next = NULL;
  return new_node;
}

pqueue pqueue_enqueue(pqueue q, Character character)
{
  assert(invrep(q));
  float priority = calculate_priority(character);
  node_t new_node = create_node(character);

  if (pqueue_is_empty(q) || q->first->iniciative <= priority)
  {
    new_node->next = q->first;
    q->first = new_node;
  }
  else
  {
    node_t aux = q->first;
    while (aux->next != NULL && aux->next->iniciative > priority)
    {
      aux = aux->next;
    }
    new_node->next = aux->next;
    aux->next = new_node;
  }

  q->size++;
  return q;
}

/* ============================================================================
IS EMPTY?
============================================================================ */

bool pqueue_is_empty(pqueue q)
{
  if ((q->size == 0) && (q->first == NULL))
  {
    return true;
  }
  return false;
}

/* ============================================================================
PEEKS
============================================================================ */

Character pqueue_peek(pqueue q)
{
  if (q->first != NULL)
  {
    Character peek = q->first->character;
    return peek;
  }
  else
  {
    return NULL;
  }
}

float pqueue_peek_priority(pqueue q)
{
  if (q->first != NULL)
  {
    float peek_priority = q->first->iniciative;
    return peek_priority;
  }
  else
  {
    return 0;
  }
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int pqueue_size(pqueue q)
{
  assert(invrep(q));
  unsigned int size = q->size;
  return size;
}

/* ============================================================================
COPY
============================================================================ */

pqueue pqueue_copy(pqueue q)
{
  assert(invrep(q));
  pqueue new_pqueue = malloc(sizeof(struct s_pqueue));
  node_t aux = q->first;
  new_pqueue->first = aux;
  node_t aux2 = new_pqueue->first;
  while (aux != NULL)
  {
    aux2->next = aux->next;
    aux = aux->next;
    new_pqueue->size++;
  }

  return new_pqueue;
}

/* ============================================================================
DESTROY!
============================================================================ */
node_t destroy_node(node_t node)
{
  assert(node != NULL);

  free(node);
  node = NULL;

  assert(node == NULL);
  return node;
}

pqueue pqueue_dequeue(pqueue q)
{
  assert(invrep(q));
  q->first = q->first->next;
  return q;
}

pqueue pqueue_destroy(pqueue q)
{
  assert(invrep(q));

  node_t aux = q->first;
  while (aux != NULL)
  {
    node_t next = aux->next;
    destroy_node(aux);
    aux = next;
  }
  free(q);
  q = NULL;

  assert(q == NULL);
  return q;
}
