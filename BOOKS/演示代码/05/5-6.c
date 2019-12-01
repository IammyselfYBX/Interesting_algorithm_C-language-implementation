/*************  Procedure isCircle *******************/
#include <string.h> 
#include <stdio.h> 

int isCircle(int n);/*判断n是否是回文数字*/
int reverse(int i); /*计算i 的倒置数*/

void main()
{
    int n;
    printf("Type a integer for judging is Circle:\n");
    scanf("%d",&n);                            /*从屏幕输入一个数*/
    if(isCircle(n))                              /*判断是回文数字*/
        printf("%d is Circle\n",n);
    else
        printf("%d is not Circle\n",n);          /*判断不是回文数字*/
    getchar();
}

int isCircle(int n)
{  /*函数isCircle 判断n是否是回文数字*/
    int m;
    m= reverse(n);
    if(m==n)
        return 1;
    else
        return 0;
}

int reverse(int i)
{   /*求i 的倒置数*/
    int m,j=0;
    m=i;
    while(m){
      j=j*10+m%10;
      m=m/10;
    }
    return j;   /*返回i的倒置数j*/
}

