#include "stdio.h"

int latterNumber(char *str)
{
    int i,count=0,flag ;
    char *p = str;
    while(*p != '\0')
    {
        if((*p>='A'&&*p<='Z')||(*p>='a'&&*p<='z') ) /*是字母*/
            flag = 1;
        else
        {
            flag++;
        }
        if(flag == 2)
            count++;
        p++;
    }
    return count;
}

main()
{
    char str[] = "This  is  a test!!  ";		/*初始化字符串*/
    printf("\n%s\n",str);						/*显示原字符串*/
    printf("This string contains %d latter.\n",latterNumber(str));		/*输出其单词个数*/
    getche();
}
