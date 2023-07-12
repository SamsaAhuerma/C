#include<stdio.h>

int main()
{
          int x;
          printf("dar un valor para:\n");
          scanf("%d", &x);
          
          if(x<0){
          x=-x;
          }
          else(x>=0){
          printf("x= %d\n",x);
          }
          return 0;
          }
