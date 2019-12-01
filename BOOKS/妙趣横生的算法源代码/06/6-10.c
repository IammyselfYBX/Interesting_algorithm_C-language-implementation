#include "stdio.h"

Marx()
{
    int x,y,z;
    for(x=1;x<30;x++)
        for(y=1;y<30;y++)
            for(z=1;z<30;z++)
            {
                if(3*x+2*y+z==50 && x+y+z==30)
                printf("%5d %5d  %5d\n",x,y,z);
            }
}

main()
{
    printf(" The solutions of Marx's topic\n");
    printf("  Men  Women  Children\n");
    Marx();
    getche();
}
