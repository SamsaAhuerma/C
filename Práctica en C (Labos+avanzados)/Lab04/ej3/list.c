#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _list{
       list_elem elem;
       list next;
};

list empty(){
    return NULL;
}

list addl(list_elem e, list l){
    list laux = NULL;
    laux = malloc(sizeof(struct _list));
    (*laux).elem = e;
    (*laux).elem = l;
    l = laux;
    
    return l;
}

bool is_empty(list l){
    bool res = (l == NULL);
    return res;
}

list_elem head(list l){
    return (*l).elem;
}

list tail(list l){
    assert(!(is_empty(l)));
    list laux = l;
    l = (*l).next;
    free(laux);

    return l;
}

list addr(list l, list_elem e){
    list p = NULL;
    list q = NULL;
    q = malloc(sizeof(struct _list));

    q->elem = e;
    q->next = NULL;

    if (!(is_empty(l))){
        p = l;
        while (!(p->next == NULL)){
              p = p->next;
        }
        p->next = q;
    }else{
        l = q;
    }
    return l;
}

int length(list l){
    list p = l;
    int res = 0;

    while (!(p == NULL)){
         res = res + 1;
           p = p -> next;
    }
    return res;
}

list concat(list l1, list l2){
     list laux = l1;
     list cl = copy_list(l2);

    if (l1 == NULL){
        l1 = cl;
    }else{
        while (!(l1->next == NULL)){
              laux = laux->next;
        }
        laux->next = cl;
    }
    return l1;
}

list_elem index(list l, int pos){
    assert(length(l) > pos);

    list_elem res;
    list laux = l;
    int i = 0;
    while (i < pos){
        laux = laux->next;
        i++;
    }
    res = laux->elem;
    return res;
}

list take(list l, int n){
    assert(length(l) >= n);

    list laux1 = l;
    list laux2 = NULL;
    int i = 0;

    if (!(n == 0)){
        while (i < n -1){
            laux1 = laux1->next;
            i++;
        }
        laux2 = laux1->next;
        laux1->next = NULL;
    }else{
        laux2 = l;
        l = NULL;
    }
    while (!(laux2->next == NULL)){
        laux1 = laux2;
        laux2 = laux2->next;
        free(laux1);
    }
    free(laux2);
    return l;
}

list drop(list l, int n){
    assert(n <= length(l));
    list laux = NULL;
    int i = 0;

    if (!(n==0)){
       while (i < n){
            laux = l;
            l = l->next;
            free(laux);
            i++;
       }
    }
    return l;
}

list copy_list(list l){
    list laux1 = NULL;
    list laux2 = NULL;
    list result = NULL;

    if (!(length(l) == 0)){
        result = malloc(sizeof(struct _list));
        laux1 = l;
        laux2 = result;

        while (!(l->next == NULL)){
            result->elem = l->elem;
            l = l->next;
            result->next = malloc(sizeof(struct _list));
            result = result->next;
        }
        result->elem = l->elem;
        result->next = NULL;

        l = laux1;
        result = laux2;
    }
    return result;
}

list destroy(list l){
    list p = NULL;

    if (!(l == NULL)){
       while (!(l->next == NULL)){
            p = l;
            l = l->next;
            free(p);
       }
       p = l;
       free(p);
       l = NULL;
       p = NULL;
    }
    return l;
}