#include "stdio.h"

int bitNumber(unsigned char c)
{
    int count = 0;
    int i;
    unsigned char cmp = (0x1<<7);
    for(i=0;i<8;i++)
    {
        if((c & cmp)!=0)			/*向与结果不为0*/
            count++;			/*变量count记录字符中’1’的个数*/
        cmp = cmp>>1;			/*常数的'1'位向右移动1位*/
    }
    return count;
}

main()
{
    unsigned char c;
    printf("Please input a character\n");		/*输入1个字符*/
    scanf("%c",&c);
    printf("The number of bit '1' in the character are %d\n",bitNumber(c)); /*输出该字符中’1’位的个数*/
    getche();
}
