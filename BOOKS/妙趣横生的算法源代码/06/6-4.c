#include "stdio.h"
proveJiaoGu(int n)
{
    int count=1;
    while(n!=1 && count<=1000){   /*阈值设为1000*/
    if(n%2==0)   /*n为偶数*/
    {
        printf("%d/2=%d\n",n,n/2);
        n = n/2;
     }
    else
    {
        printf("%d*3+1=%d\n",n,n*3+1); /*n为奇数*/
        n=n*3+1;
    }
    count++;
    }
    if(count<1000 && n==1)
        printf("This natural number  is according to JiaoGu Guess\n");
}

main()
{
    int n;
    printf("Please input a number to verify\n");
    scanf("%d",&n);
    printf("-------- Step of Verification---------\n");
    proveJiaoGu(n);
    getche();
}
