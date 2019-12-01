#include "stdio.h"

main()
{
    char husband[3] = {'A','B','C'}, wife[3] = {'X','Y','Z'};
    int i ,j ,k;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                if(i!=j && j!=k && i!=k) /*不能1个新娘配2个新郎*/
                {
                    /*得到一种配对方式*/
                    if (match(i,j,k,wife))
                    {
                        printf("husband  wife\n");
                        /*这种配对方式符合题目要求*/
                        printf("A---------%c\n",wife[i]);
                        printf("B---------%c\n",wife[j]);
                        printf("C---------%c\n",wife[k]);
                    }
                }

                getche();
}

int match(int i,int j,int k,char wife[])
{
    /*A不和X结婚*/
    if(wife[i] == 'X') return 0;
    /*X不和C结婚*/
    if(wife[k] == 'X') return 0;
    /*C不和Z结婚*/
    if(wife[k] == 'Z') return 0;
    return 1;
}

