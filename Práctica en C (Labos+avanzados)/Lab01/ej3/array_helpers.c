#include "array_helpers.h"
#include <stdio.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath){
    unsigned int i = 0;
    unsigned int tam;
    FILE *archivo;
    archivo = fopen(filepath,"r");

    fscanf(archivo, "%u", &tam);

    while (i < max_size){
        fscanf(archivo, "%d",&array[i]);
            i++;
    }
    fclose(archivo);
    return tam;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++){
        printf("%d", a[i]);
        if (i != length - 1){
            printf(", ");
        }
    }
    printf("]");
}