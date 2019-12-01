#include "stdio.h"
main()
{
    int a,maxVal=-1000,secondVal=-1000,i;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&a);
        if(a>maxVal)
        {
            secondVal = maxVal;
            maxVal = a;
        }
        else
        {
            if(a>secondVal)
            secondVal = a;
        }
    }
    printf("The max value is    %d\n",maxVal);
    printf("The second value is %d\n",secondVal);
    getche();
}
