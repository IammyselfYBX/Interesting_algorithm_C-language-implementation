#include "stdio.h"
void trans(int n)
{
    int i;
    i = n % 10;     /*得到整数n的个位数字*/
    if(n/10>0)
    trans(n/10);   /*递归调用trans，将高位数转换为字符串*/
    printf("%c",i+48);
}

main()
{
    printf("The translation of 12345 from interger to string\n");
    trans(1235);
    getche();
}
