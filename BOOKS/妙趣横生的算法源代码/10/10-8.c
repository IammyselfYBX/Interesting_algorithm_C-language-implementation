#include "stdio.h"
char upper(char c)
{
    return(c-'a'+'A');
}

void func(char str[],int n,int i)
{
    if(i<n)
    {
        printf("%c%c",upper(str[n-i-1]),str[i]);
        func(str,n,i+1);
    }
}

main()
{
	char str[5]={'a','b','c','d','e'};
	printf("The string of transferation is\n");
        func(str,5,0);
        getche();
}
