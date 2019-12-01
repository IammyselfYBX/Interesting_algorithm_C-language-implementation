#include "stdio.h"
insertsort(int a[],int n)                        /*直接插入排序*/
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        a[0] = a[i];
        j = i - 1;
        while(j>0 && a[0]>a[j])                    /*改变判断条件，实现从大到小地排列*/
            a[j+1] = a[j--];
        a[j+1] = a[0];                        /*将元素a[0]插入指定位置*/
    }
}

main()
{
    int i,a[11] = {-111,2,5,6,3,7,8,0,9,12,1};        /*初始化序列，a[0]可任意置数*/
    printf("The orginal data array is\n") ;
    for(i=1;i<=10;i++)                        /*显示原序列之中的元素*/
        printf("%d ",a[i]);
    insertsort(a,10);                            /*插入排序*/
    printf("\nThe result of insertion sorting for the array is\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);                        /*输出排序后的结果*/
    getche();
}

