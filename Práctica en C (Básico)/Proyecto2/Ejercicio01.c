#include<stdio.h>
#include<assert.h>

int pedirEntero(void)
{
          int x;
          printf("ingresa un entero:\n");
          scanf("%d", &x);
          return x;
          
         }

void holaHasta(int n)
{
          int i;
          i=0;
          assert(n>0);
          while(i<n){
          printf("Hola\n");
          i=i+1;
          }

int main()
{
          holaHasta(pedirEntero());
          return 0;
          }

