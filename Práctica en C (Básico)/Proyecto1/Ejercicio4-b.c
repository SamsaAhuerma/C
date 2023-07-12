#include<stdio.h>

/*Ejercicio 4-b*/

void funcion(int x, int y, int z, int m){
          if(x<y){
          (m=x);
          }
          else{
          (m=y);
          }
          if(m>=z){
          (m=z);
          }
          printf("resultado:\nx = %d\ny = %d\nz = %d\nm = %d\n", x,y,z,m);
          }
          
int main(void){
          int x,y,z,m;
          printf("ingrese un valor para x\n");
          scanf("%d", &x);
          printf("ingrese un valor para y\n");
          scanf("%d", &y);
          printf("ingrese un valor para z\n");
          scanf("%d", &z);
          printf("ingrese un valor para m\n");
          scanf("%d", &m);
          
          funcion(x,y,z,m);
          }
