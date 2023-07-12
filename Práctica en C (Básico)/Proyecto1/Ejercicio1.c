#include<stdio.h>

int funcion(int x, int y, int z)
{
          printf(" x + y + 1 me da como resultado %d\n", x + y + 1);
          printf("z * z + y * 45 - 15 * x me da como resultado %d\n", z * z + y * 45 - 15 * x);
          printf("y / 2 * x me da como resultado %d\n", y/2 * x);
          
          if (y-2 == (x * 3 + 1)%5){
          printf("True");
          }
          else{
          printf("False");
          }
          
          if (y < x*z){
          printf("True");
          }
          else{
          printf("False");
          }
          return 0;
}
          
int main(void)
{
          funcion(7,3,5);
          funcion(1,10,8);
          return 0;
          }
          

/*En la ultima expresion el resultado en lenguage C es de tipo Bool, ya que los booleanos en c estan representados con unos y ceros*/
 /*
                x->7 y->3 z->5                    x->1 y->10 z->8
    expresion1 :    11                                  12
    expresion2 :    55                                 499
    expresion3 :    0   (False)                         0 (False)
    expresion4 :    7                                   5
    expresion5 :    1   (True)                          0 (False)
    */ 

/*------------*/

