#include "stdio.h"
main()
{
    char c;
    printf("Please input a character\n");
    scanf("%c",&c);
    getchar();
    printf("The ASCII of %c is %d\n",c,c);
}

