#include "stdio.h"

long reverse(long i)
{   /*求i 的倒置数*/
    long m,j=0;
    m=i;
    while(m){
      j=j*10+m%10;
      m=m/10;
    }
    return j;   /*返回i的倒置数j*/
}

long isCircle(long n)
{  /*函数isCircle 判断n是否是回文数字*/
    long m;
    m= reverse(n);
    if(m==n)
        return 1;
    else
        return 0;
}

palindrome(long low,long high)
{
    long i;
    for(i=low;i<=high;i++)
    {
        if(isCircle(i) && isCircle(i*i) && isCircle(i*i*i))
        printf("%d ",i);
    }
}

main()
{
  printf("The palindrome numbers between 11~999 are\n");
  palindrome(11,999);
  getche();
}
