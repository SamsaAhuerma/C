#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack{
    stack_elem elem;
    unsigned int length;
    stack next;
};

bool invrep(stack s){
    s=s;
    return true;
}

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack punt  = NULL;
    punt =  malloc(sizeof(struct _s_stack));

    punt->elem = e;
    punt->next = s;
    
    if (s == NULL){
        punt ->length = 1u;
    }else{
        punt-> length = s-> length + 1;
    }
    
    s = punt;
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));
    assert(s != NULL);

    stack punt = s;
    punt = malloc(sizeof(struct _s_stack));

    punt = s->next;
    free(punt);
    punt = NULL;

    assert(invrep(s));
    return s; 
}

//obtiene el tam de la pila
unsigned int stack_size(stack s){
    assert(invrep(s));
    unsigned int tam = 0;

    while (s != NULL){
        tam = s->length;
    }
    assert(invrep(s));
    return tam;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    assert(s != NULL );

    assert(invrep(s));

    return s->elem;
}

bool stack_is_empty(stack s){
    assert(invrep(s));

    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    
    stack p = s;
    stack_elem * array = NULL;

    if (s != NULL){
        array = calloc(stack_size(s), sizeof(stack_elem));

        for (int i = (stack_size(s)-1); i >= 0; i--){
            array[i] = p->elem;
            p = p->next;
        }
    }
    assert(invrep(s));

    return array;
}

stack stack_destroy(stack s){
    assert(invrep(s));
    stack p = NULL;

    while (s != NULL){
          p = s;
          s = s->next;
          p->next = NULL;
          free(p);
    }
    p = NULL;

    assert(invrep(s));

    return s;
}
// invrep es una fun booleana que usamos para verificar que la instancia que se le pasa como parametro cumpla las propiedades de la inv 