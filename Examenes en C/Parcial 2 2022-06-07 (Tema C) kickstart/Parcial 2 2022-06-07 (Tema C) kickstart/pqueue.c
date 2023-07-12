#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue { //comple 
    struct s_node ** array;
    unsigned int size;
    priority_t min_priority;
    priority_t priority;
};

struct s_node { //compl
    pqueue_elem elem;
    struct s_node *next;
};

//devuelve el que mas prioridad de los dos tenga.
static priority_t mas_alta_prio (priority_t a, priority_t b){
    return a < b ? a : b; 
}

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=NULL;
    new_node = malloc(sizeof(struct s_node)); //agregue esta linea.
    assert(new_node!=NULL);
    new_node -> next = NULL; //compl desde aca
    new_node -> elem = e; //hasta aca
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    free(node); //complet desde aca
    node = NULL; 
    return node;
}

static priority_t pqueue_actual_peek_priority(pqueue q){
    priority_t priori;

    for(unsigned int i = 0; i <= q->min_priority; i++){ // itero sobre todas las prioridades hasta encontrar la mas alta
        if (q->array[i] != NULL){
            priori = i; //la mas alta es la primera que encuentro
            break; //salta directamente al ultimo si pasa algo
        }
    }

    return priori;
}

static bool invrep(pqueue q) {
//evaluo que la cola sea valida
    bool valid = q!=NULL;
    struct s_node *curr;

    //chequeo que el array no sea NULL y que el min_priority sea mayor o igual a 0
    unsigned int actual_size = 0;
    if (valid){
        for(unsigned int i = 0; i<=q->min_priority;i++){
            curr = q -> array[i];
            while(curr != NULL){
                ++actual_size; //cuenta la cant de elementos
                curr = curr-> next; //avanza al siguiente
            }
        }
        valid = actual_size == q-> size; //si la cant de elem es igual a la cant de elem q dice tener la cola, es valida
    }

    //creck that peek priority corresponds to the actual peek priority, unless the pqueue is empty
    if(valid && actual_size > 0){
    valid = q->priority == pqueue_actual_peek_priority(q);
}
return valid; //hasta aca
}

pqueue pqueue_empty(priority_t min_priority) { //crea una cola de prio vacia para almacenar prio <= min_priority
    pqueue q=NULL;
    q = malloc (sizeof(struct s_pqueue)); //comp desde aca
    q -> size = 0;
    //la prioridad de peek es incialmente un numero mayor q cualq prioridad posible
    q -> priority = min_priority+1;
    q->min_priority = min_priority;
    q->array = malloc(sizeof(struct s_node*) * (min_priority+1)); //crea un array de punteros a nodos
    for(unsigned int i = 0; i<=min_priority; i++){ //inicializa el array en null
        q->array[i] = NULL; //hasta aca
    }
    assert(invrep(q));
    assert (pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) { // inserta un elem a la cola con su corresp prio
    assert(invrep(q));
    assert(priority <= q -> min_priority); //compl desde aca

    struct s_node *new_node = create_node(e);

    if(q->array[priority] == NULL){
        q->array[priority] = new_node;
    }else {
        //obtiene el ultimo elemento de la cola
        struct s_node *curr = q -> array[priority];
        //inserta el nuevo nodo al final de la cola
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr -> next = new_node;
    }
    ++q->size;
    q -> priority = mas_alta_prio(priority, q-> priority); //hasta aca

    assert(invrep(q));
    assert (!pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) { //indic si la cola de prio esta vacia
    assert(invrep(q));
    return q->size == 0; //modif esta linea
}

pqueue_elem pqueue_peek(pqueue q) { //obtiene el elem con may prio
    assert(invrep(q) && !pqueue_is_empty(q));
    pqueue_elem peek; // compl desde aca
    for(unsigned int i = 0; i <= q -> min_priority; i++) {
        if(q->array[i] != NULL){
            peek = q -> array[i]->elem;
            break;
        }
    }

    return peek; // hasta aca
}

priority_t pqueue_peek_priority(pqueue q) { // obtiene el valor de la prio del elem con mayor prio
    assert(invrep(q) && !pqueue_is_empty(q));
    return q -> priority; //modif aca
}

size_t pqueue_size(pqueue q) { //ontiene el tamaño de la cola de prio.
    assert(invrep(q));
    return q->size; //modf aca
}

pqueue pqueue_dequeue(pqueue q) { // quita un elemento con may prio mas antiguo de la cola
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t priori = q -> priority; //compl desde aca
    struct s_node *killme = q -> array [q->priority];
    q->array[priori] = q -> array[q->priority]-> next;
    destroy_node(killme);
    --q->size;

    //prioridad de actualizacion
    //si la cola fuera de cola esta vacia, la priorirdad sera min_priority+1
    while(q->priority<=q->min_priority && q-> array[q->priority] == NULL){ //la prioridad es valida y su cola corresp esta vacia
        ++(q->priority); // hasta aca
    }
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) { //destruye una instancia del TAD cola de prioridades
    assert(invrep(q));
    struct s_node *killme; //compl desde aca
    for (unsigned int i = 0; i <= q ->min_priority; i++){
        while(q->array[i] != NULL){
            killme = q -> array[i];
            q -> array[i] = q -> array[i]-> next;
            destroy_node(killme);
        }
    }
    free(q->array);
    free(q);
    q = NULL; // hasta aca.
    return q;
}

