/*Ejercicio 3*/
#include <stdio.h>
#include <assert.h>

/*Programa a*/
int main(void) /*Se ejecuta con x=1, x=5, x=cualquier valor dentro de los enteros*/
{
          int x;
          printf("Ingrese un valor para x\n");
          scanf("%i", &x);
          //assert(x==1);
          return 0;
          }
          
/*               Entrada                Salida
    1_a Ejec 1    x->10                  x->5
    1_a Ejec 2    x->20                  x->5
    1_a Ejec 3    x->14                  x->5
*/
