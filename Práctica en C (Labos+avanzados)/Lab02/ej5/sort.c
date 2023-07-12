#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i,j,piv;
    piv = izq;
    i = izq + 1;
    j = der;
    while (i <= j){
        if (a[i] <= a[piv]){
            i++;
        }if (a[j] >= a[piv]){
            j--;
        }if (a[i] > a[piv] && a[j] < a[piv]){
            swap(a,i,j);
        }
        i++; 
    }
    swap(a,piv,j);
    piv = j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        unsigned int piv = partition(a,izq,der);
        quick_sort_rec(a,izq,piv-1);
        quick_sort_rec(a,piv+1,der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


