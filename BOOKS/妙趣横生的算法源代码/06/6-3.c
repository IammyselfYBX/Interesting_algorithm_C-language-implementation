#include "stdio.h"

void func()
{
    int a,b,c,d;
    for(a=1;a<=9;a++)
        for(b=0;b<=9;b++)
            for(c=0;c<=9;c++)
                for(d=0;d<=9;d++)
                {
                  if(a*1000+b*100+c*10+d == ((a*10+b) +(c*10+d))* ((a*10+b) +(c*10+d)))
                        printf("%d%d%d%d\t",a,b,c,d);
                }
}

main()
{
    printf("There are following numbers according with the condition\n");
    func();
    getche();
}
