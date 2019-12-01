#include"stdio.h"
main()
{
    char str[11]={'a','b','d','f','h','j','l','p','t'},c;
    int i,j;
    printf("Please input a alpha\n");
    scanf("%c",&c);
    for(i=0;i<9;i++)
        if(str[i]>=c)break;
    if(i<9)
    for(j=8;j>=i;j--)
        str[j+1]=str[j];
    str[i]=c;
    printf("The result is\n");
    printf("%s",str);
    getche();
}
