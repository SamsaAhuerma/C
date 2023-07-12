#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    
    if (x >= 0){
        y= x;
    }else{
        y= -x;
    }
}

int main(void) {
    int a=0, res=0;
   
    a = -10;
    absolute(a,res);
    printf("res= %d\n",res);
    return EXIT_SUCCESS;
}

/*
No devuelve el resultado esperado, pero es porque estamos cambiando el valor que tiene la variable dentro
de la "vida" que tiene dentro de la funcion, no altera su valor original que está guardado en otra posición de memoria,
incluso si lo hiciera utilizando pointers dentro de absolute me devolvería el mismo valor
*/