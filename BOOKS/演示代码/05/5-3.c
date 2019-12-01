/***********************Procedure Goldbach Guess*******************************/
#include <string.h> 
#include <stdio.h> 

int isGoldbach(int a);
int TestifyGB_Guess(int low,int high);
int isPrime(int i);
void main()
{
    /*验证1~100以内的歌德巴赫猜想*/
    printf("Now testify Goldbach Guess in the range of 1~100\n\n");
    if(TestifyGB_Guess(1,100))
        printf("\nIn the range of 1~100,Goldbach Guess is right.\n");
    else  printf("\nGoldbach Guess is wrong.\n");
    getchar();
}
 
int TestifyGB_Guess (int low,int high)
{/*在low和high的范围内验证歌德巴赫猜想*/
    int i,j=0;
    int flag=0;
    for(i=low;i<=high;i++)
        if(i%2==0&&i>2)
            if(isGoldbach(i)){           /*偶数i符合歌德巴赫猜想*/
            j++;                         /*j用来控制输出格式*/
            if(j==5){
                printf("\n");
                j=0;
                }
            }
            else
            {flag=1;break;}
    if(flag==0)
        return 1;            /*在low和high的范围内歌德巴赫猜想正确返回1*/
    else
        return 0;               /*在low和high的范围内歌德巴赫猜想不正确返回0*/
}

int isGoldbach(int a)
{/*判断偶数a是否符合歌德巴和猜想*/
   int i,flag=0;
   for(i=1;i<=a/2;i++)
   {
        if(isPrime(i)&& isPrime(a-i))     /*如果i和a-i都为素数，则符合歌氏猜想*/
        {
            flag=1;
            printf("%d=%d+%d ",a,i,a-i);
            break;
        }
   }
   if(flag==1)
        return 1;           /*a符合歌德巴赫猜想返回1*/
   else
        return 0;          /*a不符合歌德巴赫猜想返回0*/
}

int isPrime(int i)
{   /*判断o是否是素数*/
    int n,flag=1;
    if(1==i)flag=0;                 /*1不是素数，素数都要大于1*/
    for(n=2;n<i;n++)
        if(i%n==0){flag=0;break;}  /*如果在2~i-1之间i有其他因子，则i不是素数,flag置0*/
    if(flag==1)
        return 1;           /*i是素数返回1*/
    else
        return 0;          /*i不是素返回0*/
}

