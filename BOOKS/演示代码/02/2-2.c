#include "stdio.h"
bin_search(int A[],int n,int key){
    int low,high,mid;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(A[mid]==key)return mid;                /*查找成功，返回mid*/
        if(A[mid]<key){
            low = mid + 1;                    /*在后半序列中查找*/
        }
        if(A[mid]>key){
            high = mid - 1;                    /*在前半序列中查找*/
        }
    }
    return -1;                                /*查找失败，返回-1*/
}
main()
{
    int A[10] = {2,3,5,7,8,10,12,15,19,21},i,n ,addr;
    printf("The contents of the Array A[10] are\n");
    for(i=0;i<10;i++)
    printf("%d ",A[i]);                            /*显示数组A中的内容*/
    printf("\nPlease input a interger for search\n");
    scanf("%d",&n);                            /*输入待查找的元素*/
    addr = bin_search(A,10,n);                    /*折半查找，返回该元素在数组中的下标*/
if(-1 != addr)                            /*查找成功*/
printf("%d is at the %dth unit is array A\n ",n,addr);
    else printf("There is no %d in array A\n",n);        /*查找失败*/
    getche();
}

