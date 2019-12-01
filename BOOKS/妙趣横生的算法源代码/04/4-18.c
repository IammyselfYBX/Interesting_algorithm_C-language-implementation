#include "stdio.h"

float Rand(int n,float x){                /*递归函数，求勒让德多项式*/
    if (n==0)  return 1;
    else if(n==1) return x;
    else return ((2*n-1)*x-Rand(n-1,x)-(n-1)*Rand(n-2,x))/n ;
}

main()
{
    int n;
    float x,p;
    printf("Please input n\n");
    scanf("%d",&n);                /*输入勒让德多项式的阶*/
    printf("Please input x\n") ;        
    scanf("%f",&x);                /*输入自变量x*/
    p = Rand(n,x);
    printf("The result of   P%d(%f) = %f\n",n,x,p) ;        /*输出结果*/
    getche();
}

