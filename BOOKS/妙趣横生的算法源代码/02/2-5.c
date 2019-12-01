#include "stdio.h"
void bubblesort(int k[],int n){                    /*冒泡排序*/
    int i,j,tmp ,flag = 1;
    for(i=1;i<=n-1 && flag == 1;i++){                /*执行n-1趟排序*/

        flag = 0;
        for(j=1;j<=n-i;j++){
            if(k[j]<k[j+1]){                    /*数据交换*/
                tmp = k[j+1];
                k[j+1] = k[j];
                k[j] = tmp;
                flag = 1;
            }
           }
        }
}

main()
{
    int i,a[11] = {-111,2,5,6,3,7,8,0,9,12,1};            /*初始化序列，a[0]可任意置数*/
    printf("The orginal data array is\n") ;
    for(i=1;i<=10;i++)                            /*显示原序列之中的元素*/
        printf("%d ",a[i]);
    bubblesort(a,10);                            /*执行冒泡排序*/
    printf("\nThe result of bubble sorting for the array is\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);                            /*输出排序后的结果*/
getche();
}

