#include<stdio.h>
#define N 5

int pedirArreglo(int a[], int n_max)
{
    int i;
    i=0;
    while (i<n_max)
    {
        printf("ingresa el valor %i\n",i);
        scanf("%i", &a[i] );
        i=i+1;
    }
    return a[N];
}

int existe_positivo(int a[], int tam)
{
    int i;
    i=0;
    while (i<tam)
    {
        if(a[i]>0){
            i=tam;
            printf("True\n");
            }
        else if (i==tam-1){
            i=tam;
            printf("False\n");}
        else{
            i=i+1;}
    }
    return 0;
}

int todos_positivos(int a[], int tam)
{
    int i;
    i=0;
    while (i<=tam)
    {
        if(a[i]<0){
            i=tam;
            printf("False\n");}
        else if (i==tam-1){
            i=tam;
            printf("True\n");}
        else{
            i=i+1;}
    }
    return 0;
}

int main()
{ 
    int a[N];
    int i;
    a[N]=pedirArreglo(a,N);
    printf("ingresá:\n0 si querés chequear que exista un positivo\n1 si querés chequear que todos son valores positivos\n");
    scanf("%d", &i ) ;
    if(i==0)
        existe_positivo(a,N);
    else
        todos_positivos(a,N);
    return 0;
    }
