/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return((*x).rank <= (*y).rank);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++){
        int j=i;
        while ( j > 0 && goes_before(a[j], a[j-1])){
             player_t aux = a[j];
             a[j] = a[j-1];
             a[j-1] = aux;

             j = j-1;
        }
        assert(array_is_sorted(a,i));
    }
}

