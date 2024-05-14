#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

struct s_list
{
    elem_t elem;
    list next;
};

list list_empty()
{
    list l = NULL;

    return l;
}

list list_add_left(elem_t e, list l)
{
    list p = NULL;
    p = malloc(sizeof(elem_t));
    p->elem = e;
    p->next = l;
    l = p;

    return l;
}

list list_add_right(elem_t e, list l)
{
    list p = NULL, q = NULL;
    q = malloc(sizeof(elem_t));
    q->elem = e;
    q->next = NULL;

    if (!list_is_empty(l))
    {
        p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = q;
    }
    else
    {
        l = q;
    }

    return l;
}

bool list_is_empty(list l)
{
    return l == NULL;
}

elem_t list_head(list l)
{
    elem_t elem;

    if (!list_is_empty(l))
    {
        elem = l->elem;
    }

    return elem;
}

list list_tail(list l)
{
    list p = NULL;

    if (!list_is_empty(l))
    {
        p = l;
        l = l->next;
        free(p);
    }

    return l;
}

int list_length(list l)
{
    list p = NULL;
    int length = 0;

    if (!list_is_empty(l))
    {
        p = l;
        length = 1;
        while (p->next != NULL)
        {
            p = p->next;
            length++;
        }
    }

    return length;
}

list list_concat(list l, list k)
{
    list p = NULL;

    if (!list_is_empty(k))
    {
        if (!list_is_empty(l))
        {
            while (p->next != NULL)
            {
                p = p->next;
            }

            p->next = k;
        }
        else
        {
            l = k;
        }
    }

    return l;
}

elem_t list_index(list l, int n)
{
    list p = NULL;
    elem_t e;
    int i = 0;

    if (list_length(l) > n)
    {
        p = l;
        while (i < n)
        {
            p = p->next;
            i++;
        }

        e = p->elem;
    }

    return e;
}

list list_take(list l, int n)
{
    list p = NULL, q = NULL;
    int i = 0;

    if (list_length(l) >= n)
    {
        p = l;
        while (i < n)
        {
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = NULL;
        list_destroy(q);
    }

    return l;
}

list list_drop(list l, int n)
{
    list p = NULL;
    int i = 0;

    if (list_length(l) >= n)
    {
        ;
        while (i < n)
        {
            p = l;
            l = l->next;
            free(p);
            i++;
        }
    }

    return l;
}

list list_copy(list l)
{
    list k = NULL, p = NULL;
    int i, length;
    elem_t e;

    if (!list_is_empty(l))
    {
        p = l;
        i = 0;
        length = list_length(l);

        while (i < length)
        {
            e = p->elem;
            k = list_add_right(e, k);
            p = p->next;
            ++i;
        }
    }
    else
    {
        k = list_empty();
    }

    return k;
}

list list_destroy(list l)
{
    list p = NULL;

    if (!list_is_empty(l))
    {
        p = l;
        while (p->next != NULL)
        {
            p = l;
            l = p->next;
            free(p);
        }
    }

    return p;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <assert.h>
// #include "list.h"

// struct Node
// {
//     list_elem elem;
//     list next;
// };

// list empty(void)
// {
//     list list = NULL;

//     return list;
// }

// list addl(list_elem x, list list1)
// {
//     list aux = NULL;

//     aux = malloc(sizeof(list));
//     aux->elem = x;
//     aux->next = list1;

//     list1 = aux;

//     return list1;
// }

// void free_list(list list1)
// {
//     free(list1);
//     list1 = NULL;
// }

// bool isempty(list list1)
// {
//     return (list1->next != NULL);
// }

// list_elem head(list list1)
// {
//     assert(!isempty(list1));
//     return list1->elem;
// }

// list tail(list list1)
// {
//     assert(!isempty(list1));

//     // list aux = NULL;

//     // aux = malloc(sizeof(list));
//     // aux = list1;

//     list1 = list1->next;
//     // free_list(aux);

//     return list1;
// }

// list addr(list_elem x, list list1)
// {
//     list p = NULL, q = NULL;
//     q = malloc(sizeof(list_elem));
//     q->elem = x;
//     q->next = NULL;

//     if (!isempty(list1))
//     {
//         p = list1;
//         while (p->next != NULL)
//         {
//             p = p->next;
//         }

//         p->next = q;
//     }
//     else
//     {
//         list1 = q;
//     }

//     return list1;
// }

// int length(list list1)
// {
//     int res = 0;
//     list aux = NULL;

//     aux = malloc(sizeof(list));
//     aux = list1;

//     while (aux->next != NULL)
//     {
//         aux->next = aux->next;
//         res++;
//     }

//     free_list(aux);

//     return res;
// }

// list concat(list list1, list list2)
// {
//     list aux = NULL;

//     aux = malloc(sizeof(list));
//     aux = list1;

//     while (aux->next != NULL)
//     {
//         aux->next = aux->next;
//     }

//     aux->next = list2;

//     free_list(aux);

//     return list1;
// }

// list_elem index(list list1, int n)
// {
//     assert(length(list1) > n);

//     list aux = NULL;
//     list_elem res;
//     int counter = 0;

//     aux = malloc(sizeof(list));
//     aux = list1;

//     while (counter != n)
//     {
//         aux->next = aux->next;
//         counter++;
//     }

//     res = aux->elem;

//     free_list(aux);

//     return res;
// }

// list take(list list1, int n)
// {
//     list aux = NULL;
//     int counter = 0;

//     aux = malloc(sizeof(list));
//     aux = list1;

//     while (counter != n)
//     {
//         aux->next = aux->next;
//         counter++;
//     }

//     aux->next = NULL;

//     free_list(aux);

//     return list1;
// }

// list copy(list list1)
// {
//     list k = NULL, p = NULL;
//     int i, length_list;
//     list_elem e;

//     if (!isempty(list1))
//     {
//         p = list1;
//         i = 0;
//         length_list = length(list1);

//         while (i < length_list)
//         {
//             e = p->elem;
//             k = addr(e, k);
//             p = p->next;
//             ++i;
//         }
//     }
//     else
//     {
//         k = empty();
//     }

//     return k;
// }
