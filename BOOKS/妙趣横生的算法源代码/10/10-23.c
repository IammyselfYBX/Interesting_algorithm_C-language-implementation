#include "stdio.h"

void overlapNumber(int array1[],int n1,int array2[],int n2)
{
    int i = 0 , j = 0;
    while(i<n1 && j<n2)
    {
        if(array1[i]>array2[j]) j++;
        else if(array1[i]<array2[j]) i++;
        else if(array1[i] == array2[j])
    	{
            printf("%d ",array1[i]);
        	i++;
        	j++;
    	}
    }
}

main()
{
    int array1[]={1,2,3,4,5,6,8};			/*初始化数组array1*/
    int array2[]={3,5,6,7,8};			/*初始化数组array2*/
    printf("The overlap number of array1 and array2 are\n");
    overlapNumber(array1,7,array2,5);	/*找出array1和array2中的相同元素*/
}
