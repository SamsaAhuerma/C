#include<stdio.h>
/*Ejercicio 4*/
/*Programa e*/

int main() 
{
int  x,y;

          printf("Ingrese un valor para\n");
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d", &y);
          if (x>=y){
          x=0;
          printf("x= %d\n",x);
          }
          else if (x<=y){
          x=2;
          printf("x= %d\n",x);
          }
          return 0;
          }
          
