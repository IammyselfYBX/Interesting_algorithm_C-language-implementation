#include "stdio.h"

int factorSum(a)            /*求a的因子和*/
{
    int i, sum = 0;
    for(i=1;i<a;i++)
        if(a%i == 0)            /*i是a的一个因子*/
            sum = sum + i;    /*累加求和*/
    return sum;            /*返回a的因子的和*/
}

int perfextnumber(int a)        /*判断a是否是完全数*/
{
    if(a == factorSum(a)) return 1;
    else return 0;
}

main()
{
    int a;
    printf("There are following perfect numbers 1~1000 are:\n");
    for(a=1;a<=1000;a++)
    {                        /*寻找1-1000以内的完全数*/
        if(perfextnumber(a))
            printf("%d ",a);
    }
    getche();
}

