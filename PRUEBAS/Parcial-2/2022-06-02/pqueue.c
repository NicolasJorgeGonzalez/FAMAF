#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

// Definición de las estructuras
struct s_pqueue
{
    node front; // Puntero al primer nodo de la cola
    unsigned int size;
};

struct s_node
{
    pqueue_elem element;
    unsigned int priority;
    node next; // Puntero al siguiente nodo
};

// Funciones auxiliares
static node create_node(pqueue_elem e, unsigned int priority)
{
    node new_node = malloc(sizeof(struct s_node));
    assert(new_node != NULL);
    new_node->element = e;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

static node destroy_node(node n)
{
    assert(n != NULL);
    free(n);
    return n;
}

static bool invrep(pqueue q)
{
    if (q == NULL)
    {
        // Si q es nulo, no hay nada que verificar
        return true;
    }

    if (q->front == NULL)
    {
        // Si la cola está vacía, no hay nada que verificar
        return true;
    }

    node node_aux = q->front;

    while (node_aux != NULL && node_aux->next != NULL)
    {
        assert(node_aux->priority <= node_aux->next->priority);
        node_aux = node_aux->next;
    }

    return true;
}

// Funciones de la cola de prioridad
pqueue pqueue_empty(void)
{
    pqueue q = malloc(sizeof(struct s_pqueue));
    assert(q != NULL);
    q->front = NULL;
    q->size = 0;
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority)
{
    assert(invrep(q));
    node new_node = create_node(e, priority);

    if (q->front == NULL || q->front->priority > priority)
    {
        // Insertar al inicio si la cola está vacía o el nuevo elemento tiene la mayor prioridad
        new_node->next = q->front;
        q->front = new_node;
    }
    else
    {
        // Insertar en la posición correcta según la prioridad
        node node_aux = q->front;
        while (node_aux->next != NULL && node_aux->next->priority <= priority)
        {
            node_aux = node_aux->next;
        }
        new_node->next = node_aux->next;
        node_aux->next = new_node;
    }
    q->size++;
    return q;
}

bool pqueue_is_empty(pqueue q)
{
    return (q == NULL || q->front == NULL);
}

pqueue_elem pqueue_peek(pqueue q)
{
    assert((q != NULL) && (!pqueue_is_empty(q)));
    return q->front->element;
}

unsigned int pqueue_peek_priority(pqueue q)
{
    assert((q != NULL) && (!pqueue_is_empty(q)));
    return q->front->priority;
}

unsigned int pqueue_size(pqueue q)
{
    assert(invrep(q));
    assert(q != NULL);
    return q->size;
}

pqueue pqueue_dequeue(pqueue q)
{
    assert((q != NULL) && (!pqueue_is_empty(q)));
    node temp = q->front;
    q->front = q->front->next;
    destroy_node(temp);
    q->size--;
    return q;
}

pqueue pqueue_destroy(pqueue q)
{
    assert(invrep(q));
    while (!pqueue_is_empty(q))
    {
        q = pqueue_dequeue(q);
    }
    free(q);
    return q;
}
