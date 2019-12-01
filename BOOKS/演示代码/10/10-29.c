#include"stdio.h"
main()
{
    char st[20],cs[5][20];
    int i,j,p;
    printf("input country's name:\n");
    for(i=0;i<5;i++)
    gets(cs[i]);
    printf("\n");
    for(i=0;i<5;i++)
    {
        p=i;
        strcpy(st,cs[i]);
    for(j=i+1;j<5;j++)
        if(strcmp(cs[j],st)<0)
        {p=j;strcpy(st,cs[j]);}   /*找到字母小的字符串*/
    if(p!=i)
    {
        strcpy(st,cs[i]);    /*实现字符串的调换*/
        strcpy(cs[i],cs[p]);
        strcpy(cs[p],st);
    }
    puts(cs[i]);
    }
    printf("\n");
    getche();
}
