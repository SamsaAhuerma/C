#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    int *p = NULL;
    p = y;
    if (x >= 0){
        *p = x;
    }else{
        *p = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración

    absolute(a,&res);
    printf("res = %d\n",res);
    res=0;

   return EXIT_SUCCESS;
}

