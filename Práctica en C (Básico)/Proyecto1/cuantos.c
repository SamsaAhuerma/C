#include <stdio.h>
#define N 4

typedef struct{
 int menores;
 int iguales;
 int mayores;
} com_p;

com_p cuantos( int a[], int tam, int elem){
          com_p cuan;
          int i,r,y,p;
          i=0;
          r=0;
          y=0;
          p=0;
          
          i=0;
          while(i< a[i])
          {
          if (elem == tam){
          cuan.iguales = r  + 1;
          r= cuan.iguales;
          }
          if (elem < tam){
          cuan.menores = y + 1;
          y= cuan.menores;
          }
          if(elem > tam){
          cuan.mayores = p+1;
          p = cuan.mayores;
          }
          i= i+1;
          return cuan;
          }
}

void pedirArreglo( int a[], int tam)
{
          int tam, pos;
          i=0;
          while( i < tam){
          printf("Dar valor para la posicion: %d\n", i);
          scanf("%d", %pos);
          i=i+1;
          }
          return;
          }
int main()
{         int lon, elem;
          com_p cuan;
          printf("Dar el largo de la longitud de mi array: %d\n", lon);
          scanf("%d", &lon);
          
          int a[lon];
          pedirArreglo(a,lon);
          
          printf("Introduzca un valor:%d\n", elem);
          scanf("%d", &elem);
          
          cuan= cuantos(a,lon,elem);
          printf("\nMayores: %d\nMenores: %d\nIguales: %d\n", cuan.mayores, cuan.menores, cuan.iguales);
          return 0;
          }
          
                    
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
