#include<stdio.h>
#include<stdbool.h>
/*Ejercicio 5-b-2*/
int main()
{
int x,i;
bool res;
int temp;
          
          printf("Dar valores a \n");
          printf("x= ");
          scanf("%d", &x);
          
          printf("i= ");
          scanf("%d", &i);
          i=2;
          
          printf("res= ");
          scanf("%d", &temp);
          res=temp;
          res=true;
          
          printf("Entonces nos queda:\n");
          
          while (i < x && res) {
          res= res && ((x % i) != 0);
          i=i+1;
          
          printf("x= %d\n", x);
          printf("i= %d\n", i);
          printf("res= %d\n", res);
          }
          
          return 0;
          }
