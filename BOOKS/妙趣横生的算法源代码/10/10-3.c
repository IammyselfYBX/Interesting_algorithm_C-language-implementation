#include "stdio.h"
float Sum(int n)
{
    int i;
    float sum = 0,a=2,b=1,tmp;
    for(i=0;i<n;i++)
    {
       sum = sum +a/b;
       tmp = a + b;
       b = a;           /*后一项的分母等于前一项的分子*/
       a = tmp;         /*后一项的分子等于前一项分母与分子之和*/
    }
    return sum;
}

main()
{
    printf("2+3/2+5/3+...=%f",Sum(50));
    getche();
}
