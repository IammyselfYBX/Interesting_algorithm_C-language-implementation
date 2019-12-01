#include "stdio.h"

void swap(int *a,int *b)
{                            /*序列中元素位置的交换*/
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void quicksort(int k[], int s,int t)
{                            /*快速排序*/
    int i,j;
    if(s<t){
        i = s;
        j = t+1;
        while(1){
            do i++;
            while(!(k[s]>=k[i] || i==t));        /*重复执行i++操作*/
            do j--;
            while(!(k[s]<=k[j] || j==s));        /*重复执行j--操作*/
            if(i<j)
                swap(&k[i],&k[j]);            /*交换k[i]和k[j]的位置*/
            else
                break;

        }
        swap(&k[s],&k[j]);                /*交换基准元素与k[j]的位置*/
        quicksort(k,s,j-1);                    /*递归排序基准元素前面的子序列*/
        quicksort(k,j+1,t);                    /*递归排序基准元素后面的子序列*/
    }
}

main()
{
    int k[10]={2,5,6,3,7,8,0,9,12,1} , i;
    printf("The orginal data array is\n") ;
    for(i=0;i<10;i++)                        /*显示原序列之中的元素*/
        printf("%d ",k[i]);
    quicksort(k,0,9);                        /*快速排序*/
    printf("\nThe result of quick sorting for the array is\n");
    for(i=0;i<10;i++)                         /*显示排序后的结果*/
        printf("%d ",k[i]);
    getche();
}

