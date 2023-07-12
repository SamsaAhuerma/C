#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack { //compl  (estruc principal)
   struct s_node *front;
   unsigned int size;

};

struct s_node { //comp (estruc de nodos.)
    pstack_elem elem;
    priority_t priority;
    struct s_node *next;    
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node)); //agregue esta linea
    assert(new_node!=NULL);
    new_node->elem=e; //compl desde aca
    new_node->priority=priority;
    new_node->next=NULL; //hasta axa
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL); 
    node->next=NULL; //compl desde aca
    free(node);
    node=NULL; //hasta aca
    assert(node == NULL); 
    return node;
}


static bool invrep(pstack s) {
    unsigned int actual_size = 0; //compl desde aca
    // Para empezar, el valor de la pila no debería ser nulo;
    bool valid = (s != NULL);

    struct s_node *p = s->front; //apunto al primer nodo de la pila
    while(valid && p != NULL) {
      // Mantenga un registro del tamaño
      ++actual_size;
      // Comprobar la validez del pedido
      valid = p->next == NULL || p->priority >= p->next->priority; //si el nodo siguiente es nulo o la prioridad del nodo actual es menor o igual a la prioridad del nodo siguiente
      p = p->next;
    }

    return valid && s->size == actual_size; //hasta aca
    return true;
}


pstack pstack_empty(void) {
    pstack s=NULL;
    s = malloc (sizeof(struct s_pstack)); //compl desde aca.
    s->front=NULL;
    s->size=0; 
    invrep(s); //hasta aca
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
   //assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    // Node to the left COMPL DESDE ACA
    struct s_node *left;
    // Node to the right
    struct s_node *right;
    left = NULL; //apunto al primer nodo de la pila
    right = s->front; //apunto al primer nodo de la pila

    while(right != NULL && new_node->priority <= right->priority) { //si el nodo sig es nulo o la prioridad del nodo actual es menor o igual a la prioridad del nodo sig
      left = right; //apunto al primer nodo de la pila
      right = right->next; //apunto al primer nodo de la pila
    }

    if(left == NULL) { // si nodo izq es nulo
      // Agregar al frente
      new_node->next = right;
      s->front = new_node; //apunto al primer nodo de la pila
    } else {
      // agregar en medio
      left->next = new_node;
      new_node->next = right;
    }

    ++s->size; //hasta aca

    return s;
}


bool pstack_is_empty(pstack s) { //indica si la cola de prioridad esta vacia
   return s->size==0; // cambie axa
}

pstack_elem pstack_top(pstack s) { //obtiene el elemento con mayor prioridad
   return s->front->elem; // cambie axa
}

priority_t pstack_top_priority(pstack s) {
    return s->front->priority; // cambie aca
}

unsigned int pstack_size(pstack s) {
    //assert(invrep(s)); //agregue esta linea.
    return s->size; //cambie axa
}

pstack pstack_pop(pstack s) {
    //assert(invrep(s)); //complete desde aca
    struct s_node *killme = s->front;
    s->front = s->front->next;
    destroy_node(killme);
    --s->size;
    //assert(invrep(s)); //hasta aca
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    struct s_node *node = s->front;//complete desde aca
    while(node != NULL) {
      struct s_node *killme = node; //guardarr el nodo a eliminar
      node = node->next;
      killme = destroy_node(killme); //alimina el nodo
    }
    free(s);
    s = NULL; //hasat aca
    assert(s == NULL);
    return s;
}

