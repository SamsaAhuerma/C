#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include <assert.h>

typedef struct _list * list;
typedef int list_elem;

list empty();
/*crea una lista vacia*/


list addl(list_elem e , list l);
/*agrega un elem e por izquierda de la lista*/


bool is_empty(list l);
/*chequea si la lista l esta vacia*/

list_elem head(list l);
/*Devuelve el primer elem de la lista l*/

list tail(list l);
/*Devuelve la lista l sin el primer elem*/

list addr(list l, list_elem e);
/*Agrega un elem al final de la lista l*/

int length(list l);
/*Devuelve la cantidad de elems de la lista l*/

list concat(list l1, list l2);
/*Concatena la lista l2 al final de la lista l1*/

list_elem index(list l, int pos);
/*Devuleve el elem que esta en la posicion pos de la lista l*/

list take(list l, int n);
/*Deja en la lista los primeros n elems*/

list drop(list l, int n);
/*Elimina de la lista los primeros n elems */

list copy_list(list l);
/*Copia la lista l en una nueva lista*/

list destroy(list l);
/*Libera memoria si es necesario*/

#endif