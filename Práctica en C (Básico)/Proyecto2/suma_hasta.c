#include<stdio.h>

int pedirEntero(void)
{
          int N;
          printf("Ingresá un entero \n");
          scanf("%d", &N);
          return N;
          }

int suma_hasta(int N)
{
          if(N<0){
          printf("Por favor inserte un valor positivo\n");
          }
          else{
          N=N*(N+1)/2;
          printf("El valor de la suma N es %\n", N);
          }
          return N;
          }

int mai()
{
          suma_hasta(pedirEntero());
          return 0;
          }
          
