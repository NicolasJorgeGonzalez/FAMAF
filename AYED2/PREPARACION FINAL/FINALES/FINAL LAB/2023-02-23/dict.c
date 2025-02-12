#include <stdlib.h>     /* malloc(), free()... */
#include <stdbool.h>    /* bool type           */
#include <assert.h>     /* assert()            */
#include "key_value.h"  /* key_t               */
#include "dict.h"       /* intarface           */

struct _s_dict {
    struct _node_t * first;
    unsigned int size;
};

// Internal structure
struct _node_t {
    key_t key;
    value_t value;
    struct _node_t *next;
};

struct _node_t * create_node(key_t k, value_t v) {
    struct _node_t *new_node=malloc(sizeof(struct _node_t));
    new_node->key=k;
    new_node->value=v;
    new_node->next=NULL;
    return new_node;
}

struct _node_t *destroy_node(struct _node_t *node) {
    node->key = key_destroy(node->key);
    node->value = value_destroy(node->value);
    free(node);
    node=NULL;
    return node;
}

static bool invrep(dict_t dict) {
    if (dict == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// --- Interface functions ---

dict_t dict_empty(void) {
    dict_t new_dict = malloc(sizeof(struct _s_dict));
    
    new_dict->first = NULL;
    new_dict->size = 0;

    return new_dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict) && word != NULL && def != NULL);

    struct _node_t *new_word = create_node(word, def);

    if (dict_length(dict) == 0)
    {
        dict->first = new_word;
        dict->size++;
    }
    else
    {
        struct _node_t *aux = dict->first;
        while ((aux->next != NULL) && (!key_eq(aux->key, word)))
        {
            aux = aux->next;
        }
        if (key_eq(aux->key, word))
        {
            aux->value = def;
        }
        else
        {
            aux->next = new_word;
            dict->size++;
        }
    }
    
    assert(invrep(dict) && dict_exists(dict, word));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict) && word != NULL);

    if (dict_exists(dict, word))
    {
        struct _node_t *aux = dict->first;
        
        while (!key_eq(aux->key, word))
        {
            aux = aux->next;
        }

        value_t result = aux->value;
        
        assert((result != NULL) == dict_exists(dict, word));
        return result;
    }
    else
    {
        return NULL;
    }
}

bool dict_exists(dict_t dict, key_t word) {
    assert(invrep(dict) && word != NULL);

    bool result = false;
    struct _node_t *aux = dict->first;

    while ((aux != NULL) && (result != true))
    {
        result = key_eq(aux->key, word);
        aux = aux->next;
    }
    
    assert(invrep(dict));
    return result;
}

unsigned int dict_length(dict_t dict) {
    assert(invrep(dict));
    return dict->size;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(invrep(dict) && word != NULL);

    if (dict_exists(dict, word))
    {
        struct _node_t *aux = dict->first;
        while (!key_eq(aux->next->key, word))
        {
            aux = aux->next;
        }
        struct _node_t *temp = aux->next;
        aux->next = aux->next->next;
        temp = destroy_node(temp);
        dict->size--;
    }

    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict));
    for (struct _node_t *check=dict->first; check!=NULL; check=check->next) {
        fprintf(file, "key: ");
        key_dump(check->key, file);
        fprintf(file, "\n");
        fprintf(file, "value: ");
        value_dump(check->value, file);
        fprintf(file, "\n\n");
    }
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));

    struct _node_t *aux = dict->first;
    while (aux != NULL) {
        struct _node_t *temp = aux;
        aux = aux->next;
        temp = destroy_node(temp);
    }

    // Solución: Actualizar el diccionario vacío
    dict->first = NULL;
    dict->size = 0;  // Importante para que dict_length(dict) == 0

    assert(invrep(dict) && (dict_length(dict) == 0));
    return dict;
}

dict_t dict_destroy(dict_t dict) { 
    assert(invrep(dict));
    dict = dict_remove_all(dict);
    free(dict);
    dict=NULL;
    assert(dict==NULL);
    return dict;
}
