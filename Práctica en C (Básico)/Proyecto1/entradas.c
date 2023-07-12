#include<stdio.h>
/*Ejercicio 6-a*/

int pedirEntero(void){
          int x;
          printf("Ingrese un entero para x\n");
          scanf("%d", &x);
          
          return x;
          }

void imprimeEntero(int x){
          printf("El valor de x es %d\n", x);
          }
          
int main()
{
          imprimeEntero(pedirEntero());
          return 0;
          }

