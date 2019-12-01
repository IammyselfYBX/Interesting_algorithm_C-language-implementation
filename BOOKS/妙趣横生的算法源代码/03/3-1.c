#include "stdio.h"
int isPrime(int n)
{                /*判断n是否是素数，是则返回1，不是则返回0*/
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

getPrime(int low,int high)
{                /*寻找[low,high]之间的素数*/
    int i;
    for(i=low;i<=high;i++)
        if(isPrime(i))
            printf("%d ",i);
}

main()
{
    int low,high;
    printf("Please input the domain for searching prime\n");
    printf("low limitation:");
    scanf("%d",&low);
    printf("high limitation:");
    scanf("%d",&high);
    printf("The whole primes in this domain are\n");
    getPrime(low,high);
    getche();
}

