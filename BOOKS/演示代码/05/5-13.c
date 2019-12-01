# include "stdio.h"

int isPrime(int a)
{  /*判断a是否是质数，是质数返回1，不是质数返回0*/
    int i;
    for(i=2;i<=a-1;i++)
    if(a % i == 0)
        return 0;      /*不是质数*/
    return 1;       /*是质数*/
}

void PrimeFactor(int n)
{  /*对参数n分解质因数*/
    int i;
    if(isPrime(n))  printf("%d ",n);
    else
    {
        for(i=2;i<=n-1;i++)
            if(n % i == 0)
            {
                 printf("%d ",i);             /*第一个因数一定是质因数*/
                 if(isPrime(n/i)) {            /*判断第二个因数是否是质数*/
                     printf("%d ",n/i);
                     break;                 /*找到全部质因子*/
                    }
                else
                    PrimeFactor(n/i);        /*递归地调用PrimeFactor 分解n/i */
            break;
            }
    }
}
main()
{
    int n;
    printf("Please input a integer for getting Prime factor\n")  ;
    scanf("%d",&n);
    PrimeFactor(n);   /*对n分解质因数*/
    getche();
}

