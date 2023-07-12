#include<stdio.h>

int main()
{
    int r,i;

    printf("r= ");
    scanf("%d", &r);

    printf("i= ");
    scanf("%d", &i);

    r = 0;
    i = 0;

    while(i < 3){
    if ((i % 2) == 1){
    r = r+1;
    }

    i = i + 1;
    }

    printf("r = %d\n", r);
    printf("i = %d\n", i);
    return 0;

}
