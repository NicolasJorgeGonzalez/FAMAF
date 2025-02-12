#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_node {
    queue_elem elem;
    nodes next;
};

struct s_queue {
    nodes first;
    unsigned int size;
};

static nodes
create_node(queue_elem e) {
    nodes new_node= malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static nodes destroy_node(nodes node)
{
    node->next = NULL;
    free(node);
    node=NULL;
    return node;
}

static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q = NULL;
    q   = malloc(sizeof(struct s_queue));

    q->first = NULL;
    q->size = 0;

    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    nodes new_node = create_node(e);
    
    if (q->first==NULL) {
        q->first = new_node;
    } 
    else {
        nodes aux = q->first;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_node;
        aux = destroy_node(aux);
    }
    q->size = q->size + 1;
    assert(invrep(q) && !queue_is_empty(q));
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}

unsigned int queue_size(queue q) {
    assert(invrep(q));
    return q->size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    nodes killme=q->first;
    q->first = killme->next;
    killme = destroy_node(killme);
    assert(invrep(q));
    return q;

}

void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    nodes node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    nodes node = q->first;
    while (node != NULL) {
        nodes killme = node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
