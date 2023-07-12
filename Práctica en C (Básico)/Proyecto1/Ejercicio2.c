/*Ejercicio 2*/
#include <stdio.h>
#include <stdbool.h>

int main()
{ 
int x,y,z,b,w;

          printf("ingrese un valor para \n");
          printf("x= ");
          scanf("%d", &x);
          printf("y= ");
          scanf("%d", &y);
          printf("z= ");
          scanf("%d", &z);
          printf("b= ");
          scanf("%d", &b);
          printf("w= ");
          scanf("%d", &w);

/* Se ejecuta con x= 4, y=-4, z=8, b=1, w=0 */       
          printf("x %% 4 ==0 = %s\n", x % 4 == 0 ? "True":"False");
          printf("x + y ==0 && y - x == (-1) * z = %s\n", x + y == 0 && y - x == (-1) * z? "True":"False");
          printf("not b && w = %s\n", ! b && w? "True":"False");
          return 0;
} 

