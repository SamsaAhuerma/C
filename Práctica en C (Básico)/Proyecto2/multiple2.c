#include<stdio.h>

int main()
{         int x,y,z,a,b,c;
          
          printf("Dar un valor para\n");
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d", &y);
          printf("z= ");
          scanf("%d", &z);
          
          a=x;
          b=y;
          c=z;
          printf("El valor de x= %d\n", b);
          printf("El valor de y= %d\n", b+a+c);
          printf("Y el valor de z= %d\n", b+a);
          return 0;
          }
