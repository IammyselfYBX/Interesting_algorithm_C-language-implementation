#include "stdio.h"
main()
{
    float m = 1.0;                /*记录(1/2)n*/
    float n = 1.0;                /*记录n!*/
    float s = 0.0;
    int i,j;                        /*前10项和*/
    for(i=1;i<=5;i++){            /*最外层循环，控制加法运算*/
        for(j=0;j<i;j++)
             m = m * 0.5;        /*计算(1/2)n */
        for(j=1;j<=i;j++)
            n = n * j;            /*计算n!*/
        s = s + m*n;             /*累加*/
        m = 1.0;
        n = 1.0;
    }
    printf("Sn = %f\n",s);            /*输出结果*/
    getche();
}

