#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main(void){
    stack prueba = stack_empty();//se crea una pila llamada prueba
    prueba = stack_push(prueba,10);//se inserta un elem con valor 10 en la pila

    printf("El tope de la pila = %d \n", stack_top(prueba));//imprime el elem en la parte sup de la pila
    prueba = stack_pop(prueba);//elimina el elem de la parte sup de la pila

    if (prueba == NULL){
        printf("Efectivamente elimino el único elemento (: \n"); 
    }

    printf("Agregue un elemento a una pila vacia!\n");
    int x;
    scanf("%d", &x);

    prueba = stack_push(prueba, x);
    printf("El tope de la pila = %d\n", stack_top(prueba));

    prueba = stack_pop(prueba);
    if (prueba == NULL){
        printf("Efectivamente elimino el unico elemento! \n");
    }
    
    stack_elem * array = stack_to_array(prueba);

    if (array == NULL){
        printf("Esta vacia \n");
    }else{
        printf("No anda bien :c\n");
    }
    return EXIT_SUCCESS;
}