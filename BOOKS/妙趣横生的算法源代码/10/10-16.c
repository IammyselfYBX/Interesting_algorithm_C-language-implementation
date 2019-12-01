#include "stdio.h"

void mystrcpy(char *src,char *dst)
{
    int i=0;
    while(src[i] != '\0')
    {
       dst[i] = src[i];
       i++;
    }
    dst[i] = '\0';
}

main()
{
    char dst[14],*src="hello world!\n";		/*设置源字符串和目的字符串*/
    printf("src: %s",src);						/*打印出源字符串src中的内容*/
    mystrcpy(src,dst);					/*调用函数mystrcpy 进行字符串拷贝*/
    printf("dst: %s",dst);						/*打印出目的字符串dst中的内容*/
    getche();
}
