#include"stdio.h"
main()
{
    int sum = 1,i;   /*sum 初始值为1，表示第十天的桃子数*/
    for(i=9;i>=1;i--)
         sum = (sum + 1) * 2 ;  /*每次循环都得出第i天的桃子数*/
    printf("The number of peach are %d\n",sum);
    getche();
}

