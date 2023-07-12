#include<stdio.h>
#include<assert.h>

int main()
{
          int x,y,z,a,b,c;
          a=0;
          b=0;
          c=0;
          printf("Ingresar valores para \n");
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d", &y);
          printf("z= ");
          scanf("%d", &z);
          a=x;
          b=y;
          c=z;
         
          printf("El valor de z= %d\n",a);
          printf("El valor de x= %d\n",b);
          printf("El valor de y= %d\n",c);
          assert(a==x && b==y && c==z);
          return 0;
          }
