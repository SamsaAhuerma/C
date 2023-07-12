#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_queue {
    unsigned int size;
    struct s_node *new_node; //
    struct  s_node *last_node;//el puntero next del ultimo nodo que se agrego
    struct s_node *first; 
};

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

/*static struct s_node * create_node(queue_elem e){
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}*/

static struct s_node * destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool invrep(queue q) {
    return q != NULL;
}
//en este tipo de fun reservamos memoria por lo que podria generar memory leaks
queue queue_empty(void) {
    queue q=NULL; // al crearla todos sus nodos no apuntan a nada, y es de size 0
    q = malloc(sizeof(struct s_queue));
    q-> first = NULL;
    q-> size = 0u;
    q->last_node = NULL;
    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    //struct s_node *new_node = create_node(e);
    if (q->first==NULL) {
        q->first = q->new_node;
        q->last_node = q->new_node;
        q->size += 1;
    } else {
        q->last_node->next= q->new_node;
    }
    assert(invrep(q) && !queue_is_empty(q) && queue_first(q) == e);
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}
unsigned int queue_size(queue q) {
    assert(invrep(q));
    unsigned int size=0;

    struct s_node *p = q-> first;

    while (p != NULL){
        size = size + 1;
        p = p->next;
    }

    return size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    //struct s_node * killme=q->first;
    q->first = q->first->next;
    q->new_node = destroy_node(q->new_node);
    assert(invrep(q));
    return q;

}

queue queue_disscard(queue q, unsigned int n){
    assert(invrep(q) && n <= q->size);
    if (n == 0){
        q = queue_dequeue(q);
    }else if(n == q->size - 1){
        q->last_node = destroy_node(q->last_node);
        q->size -= 1;
        struct s_node *new_last = q->first;
        for (size_t i = 1; i < q->size; i++){
           new_last = new_last->next; 
        }
        q->last_node = new_last;
        q->last_node->next=NULL;
        }else{
            struct s_node *killme, *p;
            p = q->first;
            for (size_t i = 0; i < n - 1  ; i++){
                p = p->next;
            }
            killme = p->next;
            p->next = killme ->next;
            killme = destroy_node(killme);
            q->size -= 1 ;
        }
        return q;
    assert(invrep(q));
}


void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}



queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}

