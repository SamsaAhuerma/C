#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s){
    bool cap_size = s-> size <= s-> capacity;
    bool res = (s != NULL);

    return res && cap_size;
}

stack tack_empty(){
    stack pila = malloc(sizeof(struct _s_stack));

    if (pila == NULL){
        printf("No hay espacio suficiente!\n");
        exit(EXIT_FAILURE);
    }
    pila-> capacity = 10;
    pila-> elems = calloc(pila-> capacity, sizeof(stack_elem));

    if (pila-> elems == NULL){
        printf("No hay espacio suficiente!\n");
    }
    pila-> size = 0;

    return pila;

}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));

    if (s-> size == s-> capacity){
        s-> elems = realloc(s-> elems, 2 * s-> capacity * sizeof(stack_elem));
    //guardamos el puntero al nuevo espacio de memoria, puede ser el mismo, o capaz tuvo q buscar memoria en otro lado

        s-> capacity = s-> capacity * 2;

        if (s-> elems == NULL){
            printf("No hay espacio suficiente!\n");
            exit(EXIT_FAILURE);
        }
    } 

    (s-> elems)[s-> size];
    s-> size++;

    assert(invrep(s));

    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));

    s-> size = (s-> size) - 1;

    assert(invrep(s));

    return s;
}

unsigned int stack_size(stack s){
    assert(invrep(s));
    return s-> size;
}

stack_elem stack_top(stack s){
        assert(invrep(s));
        assert(s-> size != 0);
        assert(invrep(s));
        return (s-> elems)[s->size - 1];
}

bool stack_is_empty(stack s){

    assert(invrep(s));
    return(s-> size == 0);
}

stack_elem *stack_to_array(stack s){

    assert(invrep(s));

    stack_elem *new_array;
    new_array = calloc(s-> size, sizeof(stack_elem));

    unsigned int i = 0; 
    while (i < s-> size){
         new_array[i] = (s-> elems)[i];
         i++;
    }
    assert(invrep(s));

    return new_array;
}

stack stack_destroy(stack s){
    free(s-> elems);
    s-> elems = NULL;
    free(s);
    s = NULL;

    return s;
}