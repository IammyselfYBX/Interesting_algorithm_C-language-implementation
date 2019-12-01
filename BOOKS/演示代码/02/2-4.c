#include "stdio.h"
void selectsort(int k[],int n)                /*选择排序*/
{
    int i,j,max;
    for(i=1;i<=n-1;i++){
         max = i;
         for(j=i+1;j<=n;j++)            /*在后n-i+1个元素中找到最小的元素位置*/
         if(k[j] > k[max])
            max = j;                /*用min记录下最小元素的位置*/
           if(max != i){                /*如果最小的元素不位于后n-i+1个元素档第1个*/
                k[0] = k[max] ;
                k[max] = k[i];            /*元素的交换*/
                k[i] = k[0];
            }
         }
}

main()
{
    int i,a[11] = {-111,2,5,6,3,7,8,0,9,12,1};        /*初始化序列，a[0]可任意置数*/
    printf("The orginal data array is\n") ;
    for(i=1;i<=10;i++)                        /*显示原序列之中的元素*/
        printf("%d ",a[i]);
    selectsort(a,10);                         /*执行选择排序*/
    printf("\nThe result of selection sorting for the array is\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);                        /*输出排序后的结果*/
    getche();
}

