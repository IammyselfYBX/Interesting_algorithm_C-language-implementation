#include "stdio.h"
void inputArray(int *array,int len)
{
    int i;
    for(i=0;i<len;i++)
    scanf("%d",array+i);
}
main()
{
    int i, array[10];
    printf("Please input data for array\n");
    inputArray(array,10);
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");
}

