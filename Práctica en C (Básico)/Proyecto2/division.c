#include<stdio.h>

typedef struct {
int cociente;
int resto;
} div_t;

div_t division(int x, int y)
{         div_t div;
          div.cociente = x/y;
          div.resto = x % y;
          printf("El cociente es= %d\ny el resto es %d\n", div.cociente, div.resto);
          return div;
          }

int pedirEntero(void){
          int x;
          printf("Ingrese un valor\n");
          scanf("%d", &x);
          return x;
          }
          
int main(void)
{
          int x, y;
          
          x= pedirEntero();
          y= pedirEntero();
          
          if(y!=0){
          division(x,y);
          }
          else{
          printf("ERROR\n");
          }
          return 0;
          }
          
         
           
           
           
