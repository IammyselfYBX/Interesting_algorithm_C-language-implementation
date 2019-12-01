#include "stdio.h"
void reverse(char *s)
{
    int len = strlen(s)-1,i=0;
    char tmp;
    while(i!=len && i<len)
    {
        tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
        i++;
        len--;
    }
}

main()
{
    char s[]="abcdefgh";
    printf("The string is %s\n",s);
    reverse(s);
    printf("The reversed string is %s\n",s);
    getche();
}
