#include "stdio.h"
void delChar(char *str,char c)
{
    char *q , *p = str;
    while(*p!='\0')
    {
        if(*p == c)
        {
           q = p;
           do{
                *q = *(q+1);
                q++;
           }
           while(*q != '\0') ;
        }
        p++;
    }
}

main()
{
    char str[] = "abcdefdhidkldn";				/*初始化字符串*/
    char c;
    printf("Input the charactor for deleting\n");
    scanf("%c",&c);							/*用户指定要删除的字符*/
    printf("The string before deleting: %s\n",str);	/*输出原字符串的内容*/
    delChar(str,c);							/*删除指定的字符*/
    printf("The string after deleting: %s\n",str);		/*输出处理后的字符串*/
    getche();
}
