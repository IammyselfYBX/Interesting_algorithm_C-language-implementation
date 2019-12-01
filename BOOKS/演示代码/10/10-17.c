#include "stdio.h"

void loopMove(char *str, int n)
{
    int i,j,strLength;
    char tmp;
    strLength = strlen(str);
    for(i=0;i<n;i++)
    {
        tmp = str[strLength-1];					/*取出字符串的最后一个元素*/
        for(j=0;j<strLength-1;j++)
        {
            str[strLength-j-1] = str[strLength-j-2];	/*前面的元素后移*/
        }
        str[0] = tmp;							/*将原字符串尾部的元素放在字符串首部*/
    }
}

main()
{
    char *str="abcdefghijklmn";					/*初始化字符串str*/
    printf("The orginal string is %s\n",str);			/*打印出该字符串*/
    loopMove(str,6);							/*循环右移6位*/
    printf("The string be loopmoved is %s\n",str);	/*打印出循环右移后的字符串str*/
    getche();
}
