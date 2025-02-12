#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matchTimeline.h"

/* ============================================================================
STRUCTS
============================================================================ */

struct s_node
{
    team team;
    event e;
    time t;
    playerNumber pn;
    struct s_node *next;
};

struct s_matchTimeline
{
    struct s_node *head;
    unsigned int home_goal;
    unsigned int away_goal;
    unsigned int size;
    
};

/* ============================================================================
INVERP & VALIDATION
============================================================================ */

static bool invrep(matchTimeline mt)
{
    // COMPLETAR
    return mt != NULL || mt == NULL; // Just for compiling, delete it
}

bool matchTimeline_is_time_and_score_valid(matchTimeline mt)
{
    // Verificar si la lista de eventos está ordenada cronológicamente
    struct s_node *current = mt->head;
    while (current != NULL && current->next != NULL)
    {
        if (current->t > current->next->t)  // Si el tiempo no está ordenado
        {
            return false;
        }
        current = current->next;
    }

    // Verificar que los goles de home y away coinciden con la cantidad de goles
    unsigned int home_goals_count = 0;
    unsigned int away_goals_count = 0;
    
    current = mt->head;
    while (current != NULL)
    {
        if (current->e == Goal)
        {
            if (current->team == Home)
            {
                home_goals_count++;
            }
            else if (current->team == Away)
            {
                away_goals_count++;
            }
        }
        current = current->next;
    }

    // Comparar los goles registrados con la cantidad de goles en los eventos
    if (home_goals_count != mt->home_goal || away_goals_count != mt->away_goal)
    {
        return false;
    }

    return true;
}

/* ============================================================================
CONSTRUCTOR
============================================================================ */

matchTimeline matchTimeline_empty(void)
{
    matchTimeline mt = malloc(sizeof(struct s_matchTimeline));
    
    mt->head = NULL;
    mt->home_goal = 0;
    mt->away_goal = 0;
    mt->size = 0;

    assert(invrep(mt));
    return mt;
}

/* ============================================================================
INSERTION
============================================================================ */

static struct s_node *create_node(team team, event e, time t, playerNumber pn)
{

    struct s_node *new_node = malloc(sizeof(struct s_node));

    new_node->team = team;
    new_node->e = e;
    new_node->t = t;
    new_node->pn = pn;
    new_node->next = NULL;

    return new_node;
}

/* ============================================================================
GOAL
============================================================================ */

matchTimeline matchTimeline_score_goal(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));
    
    if (matchTimeline_size(mt) == 0)
    {
        struct s_node *new_node = create_node(team, Goal, t, pn);
        
        mt->head = new_node;
    }
    else
    {
        struct s_node *aux_1 = mt->head->next;
        struct s_node *aux_2 = mt->head;
        struct s_node *new_node = create_node(team, Goal, t, pn);
        
        if (aux_2->t >= t)
        {
            new_node->next = mt->head;
            mt->head       = new_node; 
        }
        else
        {
            while ((aux_1 != NULL) && (aux_1->t >= t))
            {
                aux_1 = aux_1->next;
                aux_2 = aux_2->next;
            }
            
            aux_2->next    = new_node;
            new_node->next = aux_1; 
        }
        // aux_1 = destroy_node(aux_1);
        // aux_2 = destroy_node(aux_2);
    }

    if (team == Home)
    {
        mt->home_goal++;
    }
    else
    {
        mt->away_goal++;
    }    

    mt->size++;
    return mt;
}

/* ============================================================================
THE CARDS
============================================================================ */

matchTimeline matchTimeline_receive_yellowCard(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));

    if (matchTimeline_size(mt) == 0)
    {
        struct s_node *new_node = create_node(team, YellowCard, t, pn);
        
        mt->head = new_node;
    }
    else
    {
        struct s_node *aux_1 = mt->head->next;
        struct s_node *aux_2 = mt->head;
        struct s_node *new_node = create_node(team, YellowCard, t, pn);
        
        if (aux_2->t >= t)
        {
            new_node->next = mt->head;
            mt->head       = new_node; 
        }
        else
        {
            while ((aux_1 != NULL) && (aux_1->t >= t))
            {
                aux_1 = aux_1->next;
                aux_2 = aux_2->next;
            }
            
            aux_2->next    = new_node;
            new_node->next = aux_1; 
        }
        // aux_1 = destroy_node(aux_1);
        // aux_2 = destroy_node(aux_2);
    }  

    /*Chequea si tiene 2 amarillas*/
    struct s_node *aux = mt->head;
    unsigned int i = 0;

    while ((aux->next != NULL) || (i == 2))
    {
        aux = aux->next;
        if ((aux->pn == pn) && (aux->e == YellowCard))
        {
            i++;
        }
        
    }

    if (i == 2)
    {
        matchTimeline_receive_redCard(mt, team, t, pn);
    }
    
    mt->size++;

    return mt;
}

matchTimeline matchTimeline_receive_redCard(matchTimeline mt, team team, time t, playerNumber pn)
{
    assert(invrep(mt));

    if (matchTimeline_size(mt) == 0)
    {
        struct s_node *new_node = create_node(team, RedCard, t, pn);
        
        mt->head = new_node;
    }
    else
    {
        struct s_node *aux_1 = mt->head->next;
        struct s_node *aux_2 = mt->head;
        struct s_node *new_node = create_node(team, RedCard, t, pn);
        
        if (aux_2->t >= t)
        {
            new_node->next = mt->head;
            mt->head       = new_node; 
        }
        else
        {
            while ((aux_1 != NULL) && (aux_1->t >= t))
            {
                aux_1 = aux_1->next;
                aux_2 = aux_2->next;
            }
            
            aux_2->next    = new_node;
            new_node->next = aux_1; 
        }
        // aux_1 = destroy_node(aux_1);
        // aux_2 = destroy_node(aux_2);
    }  

    mt->size++;

    return mt;
}

/* ============================================================================
SCORE
============================================================================ */

unsigned int matchTimeline_get_score(matchTimeline mt, team team)
{
    assert(invrep(mt));

    if (team == Home)
    {
        return mt->home_goal;
    }
    else
    {
        return mt->away_goal;
    }
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int matchTimeline_size(matchTimeline mt)
{
    assert(invrep(mt));
    return mt->size;
}

/* ============================================================================
PRINT
============================================================================ */

void matchTimeline_print(matchTimeline mt)
{
    fprintf(
        stdout, "            Home %u -  %u Away \n", 
        matchTimeline_get_score(mt, Home), 
        matchTimeline_get_score(mt, Away)
    );

    struct s_node *aux = mt->head;
    while (aux != NULL)
    {
        unsigned int t = aux->t;
        char *e;
        switch (aux->e)
        {
        case Goal:
            e = "    Goal   ";
            break;
        case YellowCard:
            e = "Yellow Card";
            break;
        case RedCard:
            e = "  Red Card ";
            break;
        }
        unsigned int pn = aux->pn;

        if (aux->team == Home) {
            fprintf(stdout, "%u - %s - %u' \n", pn, e, t);
        }
        else {
            fprintf(stdout, "                   %u' - %s - %u \n", t, e, pn);
        }

        aux = aux->next;
    }
}

/* ============================================================================
ARRAY
============================================================================ */

event *matchTimeline_events_array(matchTimeline mt)
{
    unsigned int length = matchTimeline_size(mt);
    
    if (length == 0) 
    {
        return NULL;
    }

    event *array = malloc(sizeof(event) * length);
    struct s_node *aux = mt->head;

    for (unsigned int i = 0; i < length; i++)
    {
        array[i] = aux->e;
        aux= aux->next;    
    }

    return array;
}

/* ============================================================================
DESTRUCTOR!
============================================================================ */

static struct s_node *destroy_node(struct s_node *node)
{
    free(node);
    node = NULL;
    return node;
}

matchTimeline matchTimeline_destroy(matchTimeline mt)
{
    assert(invrep(mt));

    struct s_node *aux = mt->head;

    while (aux != NULL)
    {
        struct s_node *temp = aux->next;
        aux = destroy_node(aux);
        aux = temp;
    }

    aux = destroy_node(aux);

    return mt;
}
