#ifndef _PAIR_H
#define _PAIR_H

typedef struct s_pair_t pair_t;

struct s_pair_t
{
    int values[2];
};

pair_t pair_new(int x, int y);
/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

int pair_first(pair_t p);
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

int pair_second(pair_t p);
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p);
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p)}
 *
 */

pair_t pair_destroy(pair_t p);
/*
 * DESC: Free memory if its necesary
 *
 */

#endif
