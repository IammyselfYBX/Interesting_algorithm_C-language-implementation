#include "stdio.h"
int reverse(i)
{
    /*求i的倒置数*/
    int r = 0;
    while(i)
    {
        r = r * 10 + i % 10;
        i = i /10;
    }
    return r;
}

int fun(int i, int j)
{
    /*判断ABCDE 5个数字是否相同*/
    int buf[4] , k = 0;
    while(i){
        buf[k] = i % 10;
        i = i / 10;
        k++;
    }
    if(buf[0] == buf[1]) return 0;   /* A跟B比较 */
    if(buf[0] == buf[2]) return 0;   /* A跟C比较 */
    if(buf[0] == buf[3]) return 0;   /* A跟D比较 */
    if(buf[0] == j)      return 0;  /* A跟E比较 */
    if(buf[1] == buf[2]) return 0;   /* B跟C比较 */
    if(buf[1] == buf[3]) return 0;   /* B跟D比较 */
    if(buf[1] == j)      return 0;  /* B跟E比较 */
    if(buf[2] == buf[3]) return 0;   /* C跟D比较 */
    if(buf[2] == j)      return 0;  /* C跟E比较 */
    if(buf[3] == j)      return 0;  /* D跟E比较 */
    return 1;
    
}

main()
{
    int i,j;
    for(i=1000;i<10000;i++)                 /*遍历4位数空间[1000，9999]*/
        for(j=1;j<10;j++)                    /*遍历1位数空间[1，10]*/
            if(i * j == reverse(i) && fun(i,j))       /*如果i,j满足题目的要求*/
               {
                printf("%d\n",i);
                printf("*  %d\n",j);
                printf("----------\n");
                printf("%d\n\n",i*j);  
         }
}

