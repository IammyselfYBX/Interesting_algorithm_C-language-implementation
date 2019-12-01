#include "stdio.h"

int factorSum(a)                /*求a的因子和*/
{
    int i, sum = 0;
    for(i=1;i<a;i++)            
        if(a%i == 0)                /*i是a的一个因子*/
            sum = sum + i;        /*通过变量sum累加求和*/
    return sum;                    /*返回a的因子的和*/
}

int isfriend(int a,int b,int i,int j)        /*判断a,b是否是亲密数，是亲密数返回1，否则返回0*/
{
    if(a==j && b== i )return 1;
    else return 0;
}

friendly()                        /*寻找1-3000范围内的亲密数*/
{
  int i , j, x[3001];
  for(i=1;i<=3000;i++)
    x[i] = factorSum(i);
  for(i=1;i<=3000;i++)
  {
    if(x[i]!=-111){
        for(j=i+1;j<=3000;j++)
            if(isfriend(x[i],x[j],i,j))
            {
                printf("(%d,%d) ",i,j);
                x[j] = -111;                ／*表示j已经找到亲密数*/
            }
    }
  }
}

main()
{
    printf("There are following friendly numbers from 1 to 3000\n");
    friendly();
    getche();
}

