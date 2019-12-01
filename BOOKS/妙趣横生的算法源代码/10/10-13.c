#include "stdio.h"
long Sum(int a,int n)
{
    int i;
    long s = 0,aa = 0;
    for(i=1;i<=n;i++)
    {
       aa = aa*10+a;
       s = s + aa;
    }
    return s;
}

main()
{
    printf("The result of 5+55+555+5555+55555 is %ld\n",Sum(5,5));
    getche();
}
