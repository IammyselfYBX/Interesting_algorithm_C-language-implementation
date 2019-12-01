#include "stdio.h"

void reverse(char *str,int i)
{
    int j=0;
    char tmp;
    while(j<i-j-1)
    {
        tmp = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = tmp;
        j++;
    }
}

void myitoa(int n ,char *str)
{
    char a;
    int i=0;
    while(n!=0)
    {
        a = n % 10;
        a = a + 48;
        str[i] = a;
        i++;
        n = n / 10;
    }
    /*i为字符串的长度*/
    reverse(str,i); /*调用函数str将字符串逆置*/
    str[i] = '\0';
}

main()
{
    int n = 1263;				/*设置整数n=1263*/
    char str[5];					/*定义字符数组，用来存放n的字符串*/
    myitoa(n,str);				/*将整数n转换为对应的字符串str*/
    printf("The integer is %d\n",n);	/*打印出整数n*/
    printf("The string of this integer is %s\n",str);	/*打印出转换后的字符串str*/
    getche();
}
