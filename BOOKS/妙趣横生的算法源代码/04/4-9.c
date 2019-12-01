#include "stdio.h"
main()
{
    int a,b;
    a=5;
    b=10;
    printf("a=%d,b=%d\n",a,b);
    a=a^b;
    b=b^a;
    a=a^b;
    printf("a=%d,b=%d\n",a,b);
    getche();
}

