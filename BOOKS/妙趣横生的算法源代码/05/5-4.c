#include "stdio.h"
/*三色球问题求解*/
main()
{
    int red,yellow,green;
    printf("red  yellow  green\n");
    for(red=0;red<=3;red++)                         /*红色：0，1，2，3*/
        for(yellow=0;yellow<=3;yellow++)               /*黄色：0，1，2，3*/
            for(green=2;green<=6;green++)        /*绿色：2，3，4，5，6*/
                if(red+yellow+green == 8)
                    printf("%d      %d      %d\n",red,yellow,green);
}

