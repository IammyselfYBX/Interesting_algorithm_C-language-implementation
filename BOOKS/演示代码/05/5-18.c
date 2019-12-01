#include "stdio.h"

getStep(int m[])            /*显示数阵中数字移动的步骤*/
{
    int i,j,tmp;
    for(i=0;i<7;i++)        /*冒泡排序*/
        for(j=0;j<7-i;j++)
        if(m[j]>=m[j+1])
        {
            tmp = m[j];
            m[j] = m[j+1];
            m[j+1] = tmp;       /*数据的交换*/
            printf("(%d# --> 0#)\n",j+1);
            printf("(%d# --> %d#)\n",j+2,j+1);
            printf("(0# --> %d#)\n",j+2);        /*输出移动步骤*/
        }
       printf("\n");
}

Print(int m[])            /*打印出当前数阵的状态*/
{
    printf("  [%d]--[%d]--[%d]\n",m[0],m[1],m[2]);
    printf("   |  %c |  %c | \n",92,47);
    printf("  [%d]--[ ]--[%d]\n",m[7],m[3]);
    printf("   |  %c |  %c | \n",47,92);
    printf("  [%d]--[%d]--[%d]\n",m[6],m[5],m[4]);
}

main()
{
    int i , m[8];
    printf("Please input 8 integer (1~8) to arrange this matrix\n");
    for(i=0;i<8;i++)
            scanf("%d",&m[i]);
    printf("The initial data matrix is like\n");
    Print(m);
    printf("\nMove Step:\n");
    getStep(m);
    printf("The result of moving is\n");
    Print(m);
    getche();
}

