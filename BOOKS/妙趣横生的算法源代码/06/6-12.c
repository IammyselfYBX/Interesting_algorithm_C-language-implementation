#include "stdio.h"

int getFalseCoin(int coin[],int low,int high)
{
    int i,sum1 = 0,sum2 = 0,sum3 = 0;
    if(low+1==high)
    {
        if(coin[low]<coin[high]) return low+1;
        else return high+1;
    }
    if((high-low+1)%2 == 0)					/*n是偶数*/
    {
        for(i=low;i<=low+(high-low)/2;i++)
            sum1= sum1 + coin[i];       		/*前半段和*/
        for(i=low+(high-low)/2+1;i<=high;i++)
            sum2 = sum2 + coin[i];       		/*后半段和*/
        if(sum1 < sum2) return getFalseCoin(coin,low,low+(high-low)/2);
        if(sum1 > sum2) return getFalseCoin(coin,low+(high-low)/2+1,high);
    }

    if((high-low+1)%2 !=0)
    {
        for(i=low;i<=low+(high-low)/2-1;i++)
            sum1= sum1 + coin[i];       		/*前半段和*/
        for(i=low+(high-low)/2+1;i<=high;i++)
            sum2 = sum2 + coin[i];       		/*后半段和*/
            sum3 = coin[low+(high-low)/2];
            if(sum1< sum2)  
                return getFalseCoin(coin,low,low+(high-low)/2-1);
        if(sum1 > sum2)         
            return getFalseCoin(coin,low+(high-low)/2+1,high);
        if(sum1+sum3 == sum2+sum3) return low+(high-low)/2+1;
    }

}
main()
{
    int coin[30] = {2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,1,2,2};
    printf("The %dth coin is false\n",getFalseCoin(coin,0,29));
    getche();
}
