#include "stdio.h"
Fibonacci(n){  /*递归函数*/
    if (n==1 || n==2) return 1;
    else
    return Fibonacci(n-1) + Fibonacci(n-2);  /*递归调用函数Fibonacci */
}
main()
{
    printf("There are %d pairs of rabbits 1 year later",Fibonacci(12));
    getche();
}

