#include<stdio.h>
#include <assert.h>
#define N 5

int pedirArreglo(int a[], int n_max)
{
    int i;
    i=0;
    while (i<n_max)
    {
        printf("ingresa el valor %i\n",i);
        scanf("%i", &a[i] ) ;
        i=i+1;
    }
    return a[N];
}

void intercambiar(int a[], int tam, int i, int j)
{
    int x0;
    x0=a[i];
    a[i]=a[j];
    a[j]=x0;
    int l;
    l=0;
    printf("los valores del arreglo son los siguientes\n");
    while (l<tam)
    {
        printf("%i-\n", a[l] ) ;
        l=l+1;
    }
}

int main()
{ 
    int a[N],i,j;
    a[N]=pedirArreglo(a,N);
    printf("Ingresá una posición a intercambiar: \n");
    scanf("%d",&i);
    printf("Ingresá otra posición a intercambiar: \n");
    scanf("%d",&j);
    assert(i!=j&&0<=i&&i<N&&0<=j&&j<N);
    intercambiar(a,N,i,j);
    return 0;
    }
