#include "stdio.h"
#include "math.h"

void getXY(int N)
{
    int x,y;
    for(x=1;x<sqrt(N);x++)
        for(y=x;y<sqrt(N);y++)
        {
            if(x*x+y*y == N)
            {
                printf("%d^2+%d^2=%d\n",x,y,N);
            }
        }
}

main()
{
    int N;
    printf("Please input a integer N\n");
    scanf("%d",&N);
    getXY(N);
    getche();
}
