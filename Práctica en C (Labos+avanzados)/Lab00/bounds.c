#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0; 
    
    for (unsigned int i = 0; i < length; i++){
        if (value == arr[i]){
            res.exists = true;
            res.where = i;
        }
        if (value > arr[i]){
            res.is_lowerbound = false;
        }if (value < arr[i]){
            res.upperbound = false;
        }    
    }  
    return res;
}



int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    printf("Ingresar un valor para value:\n");
    scanf("%i",&value);

    for (unsigned int i = 0; i < ARRAY_SIZE; i++){
        printf("Ingresar un valor para la posicion a[%i]\n", i);
        scanf("%i", &a[i]);
    } 
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

