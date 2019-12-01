#include "stdio.h"

void overlapNumber(int array1[],int n1,int array2[],int n2)
{
    int i,j;
    for(i=0;i<n1;i++)
        for(j=0;j<n2;j++)
    	{
            if(array1[i] == array2[j])
            {
                printf("%d ",array1[i]);
                break;
            }
    	}
}

main()
{
    int array1[]={2,3,4,5,6};				/*初始化数组array1*/
    int array2[]={3,5,7,2,10,-1};				/*初始化数组array2*/
    printf("The overlap number of array1 and array2 are\n");
    overlapNumber(array1,5,array2,6);		/*找出array1和array2中的相同元素*/
    getche();
}
