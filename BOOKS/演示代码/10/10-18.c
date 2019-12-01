#include "stdio.h"

void getMax(char *str,int *max0,int *max1)
{
    int i,len,tmp_max0 = 0, tmp_max1 = 0;
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='0')
        {
            if(str[i-1] == '1')
            {
                if(tmp_max1>*max1)
                    *max1 = tmp_max1;
                tmp_max1 = 0;
            }
            tmp_max0++;
        }
        if(str[i]=='1')
        {
            if(str[i-1] == '0')
            {
                if(tmp_max0>*max0)
                    *max0 = tmp_max0;
                tmp_max0 = 0;
            }
            tmp_max1++;
        }
    }
    if(tmp_max1>*max1)
      *max1 = tmp_max1;
    if(tmp_max0>*max0)
      *max0 = tmp_max0;
}

main()
{
    char *str="101000000000011100000000000";
    int max0 = 0, max1 = 0;
    getMax(str,&max0,&max1);
    printf("\n%s\n",str);
    printf("The number of consecutive character '0'are %d\n",max0);
    printf("The number of consecutive character '1'are %d\n",max1);
    getche();
}
