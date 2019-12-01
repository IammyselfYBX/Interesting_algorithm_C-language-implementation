#include "stdio.h"

void reverser(char *s,int len,int i)
{
    char tmp;
   if(i<len)
   {
        tmp = s[len];
        s[len] = s[i];
        s[i] = tmp;
        reverser(s,len-1,i+1);
   }
}

void reverse(char *s)
{
    int len = strlen(s);
    len--;
    reverser(s,len,0);
}

main()
{
    char s[]="abcdefg";
    printf("The original string is %s\n",s);
    reverse(s);
    printf("The reversed string is %s\n",s);
    getche();
}
