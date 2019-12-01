#include "stdio.h"

void cntnsIntSum(int n)
{
    int i,sum=0,j;
    for(i=1;i<n;i++)
    {
        j = i-1;
        while(sum<n)
        {
            j++;
            sum = sum + j;
        }
        if(sum == n)
        {
           printf("%d+...+%d = %d\n",i,j,n);

        }
        sum = 0;
    }
}

main()
{
    int n;
    printf("Please input a integer\n");
    scanf("%d",&n);
    cntnsIntSum(n);
    getche();
}
