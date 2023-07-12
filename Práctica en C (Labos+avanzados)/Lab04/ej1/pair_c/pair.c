#include <stdio.h>
#include "pair.h"
#include <assert.h>

struct s_pair_t{
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t result = NULL;
    result =  malloc(sizeof(pair_t));
    (*result).fst = x;
    (*result).snd = y;

    assert((*result).fst == x);
    assert((*result).snd == y);

    return result;
}

int pair_first(pair_t p){
    assert((*p).fst == (*p).fst);
    return (*p).fst;
}

int pair_second(pair_t p){
    assert((*p).snd == (*p).snd);
    return (*p).snd;
}

pair_t pair_swapped(pair_t p){
    pair_t result = NULL;
    result = malloc(sizeof(pair_t));
    
    (*result).fst = (*p).snd;
    (*result).snd = (*p).fst;

    assert((*result).fst == (*p).snd);
    assert((*result).snd == (*p).fst);
    return result;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}

