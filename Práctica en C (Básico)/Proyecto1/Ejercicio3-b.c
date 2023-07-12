/*Ejercicio 3*/
/*Programa b*/
#include <stdio.h>
#include <assert.h>

int main(void) 
{
          int x,y;
          
          printf("Dar valores para \n");
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d",&y);
          printf("Da como resultado %d\n", x + y);
          printf("Da como resultado %d\n", y + y);
          //assert(x==2 && y==5);
          return 0;
          }

/* Programa      Entrada           Salida
    1_b Ejec 1    x->3, y->7        x-> 10 , y->14
    1_b Ejec 2    x->10, y->20      x-> 30 , y->40
    1_b Ejec 3    x->1, y->2        x-> 3 , y->4  */



