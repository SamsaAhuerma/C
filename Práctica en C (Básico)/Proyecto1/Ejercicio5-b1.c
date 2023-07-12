#include<stdio.h>
/*Ejercicio 5-b-1*/
int main(){
int i,x,y;
          i=0;
          printf("Dar valores a \n");
          printf("i= ");
          scanf("%d", &i);
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d", &y);
          
          printf("Entonces \n");
          
          while (x>=y) {
          x= x-y;
          i=i+1;
          
          printf("x= %d\n", x);
          printf("i= %d\n", i);
          printf("y= %d\n", y);
          }
          
          return 0;
          }

/*
luego del iter. 1
[|σ: (x->10 ,y->3 ,i ->1)|]

luego del iter. 2
[|σ: (x->7  ,y->3  ,i ->2)|]

luego del iter. 3
[|σ: (x->4  ,y->3  ,i ->3)|]

luego del iter. 4
[|σ: (x->1  ,y->3  ,i ->4)|]
*/
