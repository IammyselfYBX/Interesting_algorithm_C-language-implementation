#include "stdio.h"
int sum(int n)
{
    if(n==1) return 1;
    else   return n+sum(n-1);
}

main()
{
    int n;
    printf("Please input a integer for counting 1+2+...+n\n");
    scanf("%d",&n);
    printf("The result of 1+2+...+%d is\n%d",n,sum(n));
    getche();
}
