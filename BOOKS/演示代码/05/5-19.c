#include"stdio.h"
#define max 100

Perm(int a[], int n ,int s ,int r[], int m){
    int i,j,k,flag=0;
    int b[max];                    /*数组b存放子序列*/
    for(i=0;i<n;i++){
        flag = 1;
        r[s] = a[i];                /*复制数列a中第i个元素到数组r*/
        j = 0;
        for(k=0;k<n;k++)            /*产生子序列b*/
            if(i != k){
                b[j] = a[k];
                j++;
            }                   
        Perm(b,n-1,s+1,r,m);        /*全排列子序列b*/
    }
if(flag == 0){                /*得到一种排列结果*/
           printf("\n");
           for(k=0;k<m;k++)
            printf("%d",r[k]);        /*输出存放排列结果的数组r中的内容*/
        printf("\n");
    }
}

main()
{
    int a[max] , r[max];
    int i,n;
    printf("Please input the number of digit inthe array\n");
    scanf("%d",&n);                /*输入待排列的数列中元素的个数*/
    printf("Please input a string for array\n");
    for(i=0;i<n;i++)                /*输入数列中的元素（整数）*/
        scanf("%d",&a[i]);
    Perm(a,n,0,r,n);                /*全排列操作*/
    getche();
}

