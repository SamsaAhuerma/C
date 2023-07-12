#include<stdio.h>
#include<assert.h>

int main()
{
          int x,y,m;
          printf("El minimo entre:\n");
          scanf("%d", &x);
          scanf("%d", &y);
          scanf("%d", &m);
          if(x<y){
          m=x;
          }
          else{
          m=y;
          }
          assert(m<=x && m<=y);
          printf("El minimo es %d\n",m);
          return 0;
          }
