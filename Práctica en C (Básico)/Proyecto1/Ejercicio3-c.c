/*Ejercicio 3*/
/*Programa c*/
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
          //assert(x==2 && y==5);
          printf("Da como resultado %d\n", y + y);
          printf("Da como resultado %d\n", x + y);
          return 0;
          }
          
/*  Programa      Entrada           Salida
    1_c Ejec 1    x->3, y->7        x->17 , y->14
    1_c Ejec 2    x->10, y->20      x->50 , y->40
    1_c Ejec 3    x->1, y->2        x->5  , y->4
*/
