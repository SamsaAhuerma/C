#include<stdio.h>
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

int sumatoria(int a[], int tam)
{
    int i,sum;
    sum=0;
    i=0;
    while (i<tam)
    {
        sum=a[i]+sum;
        i=i+1;
    }
    printf("la suma total es ");
    printf("%d\n",sum);
    return 0;
}

int main()
{ 
    int a[N];
    a[N]=pedirArreglo(a,N);
    sumatoria(a,N);
    return 0;
    }
