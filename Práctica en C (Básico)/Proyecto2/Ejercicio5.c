#include<stdio.h>
#define N 3

int pedirArreglo(int a[], int n_max)
{
          int i;
          i=0;
          while(i<n_max){
          printf("Ingrese el valor para la posicion en %d\n",i);
          scanf("%d", &a[i]);
          i=i+1;
          }
          return a[N];
          }

void imprimeArreglo(int a[], int n_max)
{
          int i;
          i=0;
          printf("Los valores del arreglo son los siguientes\n");
          while(i< n_max){
          printf("%i\n", a[i]);
          i=i+1;
          }
}
        
int main()
{
          int a[N];
          a[N]= pedirArreglo(a,N);
          imprimeArreglo(a,N);
          return 0;
          }
          
