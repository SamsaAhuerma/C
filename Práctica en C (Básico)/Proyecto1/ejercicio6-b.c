#include<stdio.h>
/*Ejercicio 6-b*/

int main(void){
          int x,y,z,m;
          
          x= pedirEntero();
          y= pedirEntero();
          z= pedirEntero();
          m= pedirEntero();
          
          funcion(x,y,z,m);
          }

/*En esta nueva version encuentro la ventaja de optimizar el código al usar menos lineas.
/*Ejercicio 4*/
/*Programa e*/
/*int main() 
{
int  x,y;

          x= pedirEntero();
          y= pedirEntero();
          if (x>=y){
          x=0;
          printf("x= %d\n",x);
          }
          else if (x<=y){
          x=2;
          printf("x= %d\n",x);
          }
          return 0;
          }

/*Programa f*/
/*int main() 
{
int  x,y;

          x= pedirEntero();
          y= pedirEntero();
          if (x>=y){
          x=0;
          printf("x= %d\n",x);
          }
          else if (x<=y){
          x=2;
          printf("x= %d\n",x);
          }
          return 0;
          }
          
          
/*Ejercicio 3*/
/*Programa b*/
/*int main(void) 
{
          int x,y
          
          x= pedirEntero();
          y= pedirEntero();
          printf("Da como resultado %d\n", x + y);
          printf("Da como resultado %d\n", y + y);
          assert(x,y) 
          return 0;
          }

/*Ejercicio 3*/        
/*Programa c*/
/*int main(void) 
{
          int x,y;
          x= pedirEntero();
          y= pedirEntero();
          printf("Da como resultado %d\n", y + y);
          printf("Da como resultado %d\n", x + y);
          return 0;
          }
         

/*Ejercicio 5-a*/
/*Programa h*/
/*int main()
{
int i;
          i= pedirEntero();
          
          printf("Entonces nos queda\n");
          
          while (i != 0) {
              i= i-1;
          
          printf("i= %d\n",i);
          }
          
          return 0;
          }
          

/*Programa i*/
/*int main()
{
int i;
          i= pedirEntero();
          
          printf("Entonces nos queda\n");
          
          while (i != 0) {
              i=0;
          
          printf("i= %d\n",i);
          }
          
          return 0;
          }
          
/*Ejercicio 5-b-1*/
/*int main()
{
int i,x,y;
          i=0;
          i= pedirEntero();
          x= pedirEntero();
          y= pedirEntero();
          
          printf("Entonces \n");
          
          while (x>=y) {
          x= x-y;
          i=i+1;
          
          printf("x= %d\n", x);
          printf("i= %d\n", i);
          }
          
          return 0;
          }
          

/*Ejercicio 5-b-2*/
/*int main()
{
int x,i;
bool res;
int temp;
          
          x= pedirEntero();
          i= pedirEntero();
          i=2;
          
          printf("res= ");
          scanf("%d", &temp);
          res=temp;
          res=true;
          
          printf("Entonces nos queda\n");
          
          while (i < x && res) {
          res= res && ((x % i) != 0);
          i=i+1;
          
          printf("res= %d\n", res);
          printf("i= %d\n", i);
          }
          
          return 0;
          } */
          
          
