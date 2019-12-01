#include "stdio.h"

main()
{
    int i,j,k;
    printf("There are different methods for TOM to distribute his book to A,B,C\n");
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            for(k=1;k<=5;k++)
                if(i!=j && j!=k && i!=k){
                    printf("(%d,%d,%d) ",i,j,k);
                    }
    getche();
}

