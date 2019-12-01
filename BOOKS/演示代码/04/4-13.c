#include "stdio.h"
deTobi(int a){
    /*将十进制数a转化为二进制表示，并打印在屏幕上*/
    int i = 0 , stack[10] , r , s;
    do{
        r = a/2;   /*商*/
        s = a%2;   /*余数*/
        stack[i] = s; 
         if(r!=0)
         {
            i++;      
            a = r;   /*将a整除2的结果作为下一个整除2的对象*/
          }
       }
    while(r);     /*循环直到商r为0为止*/
    for(;i>=0;i--)
    printf("%d",stack[i]);
    printf("\n");
}

main()
{
    int a;
    printf("Please input a Decimal digit\n");
    scanf("%d",&a);
    deTobi(a);
    getche();
}

