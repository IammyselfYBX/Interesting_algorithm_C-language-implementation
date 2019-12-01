#include "stdio.h"
int gcd(int a,int b){
    /*最大公约数*/
    int min;
    if(a<=0||b<=0) return -1;
    if(a>b) min = b;                       /*找到a,b中的较小的一个赋值给min*/
    else min = a;
    while(min){
    if(a%min == 0 && b%min == 0)       /*判断公因数*/
    return min;                    /*找到最大公约数,返回*/
    min--;                              /*没有找到最大公约数,min减1*/
    }
    return -1;
}

int lcm(int a,int b){
    /*最小公倍数*/
    int max;
    if(a<=0||b<=0) return -1;
    if(a>b) max = a;
    else max = b;      /*找到a,b中的较大的一个赋值给max*/
    while(max){
    if(max%a == 0 && max%b == 0)       /*判断公倍数*/
    return max;                  /*找到最小公倍数,返回*/
    max++;                            /*没有找到最小公倍数,max加1*/
    }
    return -1;
}

main()
{
    int a,b;
    printf("Please input two digit for getting GCD and LCM\n");
    scanf("%d %d",&a,&b);         
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));       /*打印出a,b的最大公约数*/
    printf("The LCM of %d and %d is %d\n",a,b,lcm(a,b));       /*打印出a,b的最小公倍数*/
    getche();
}

