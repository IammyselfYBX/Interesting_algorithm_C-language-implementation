#include "stdio.h"
int getSaddlePoint (int *x,int *y,int (*A)[5],int m,int n)
{
    int max , i, j , k ,flag;
    for(i=0;i<m;i++) {            /*逐行扫描寻找鞍点*/
        max = 0;                    /*max记录第i行中最大值的列数*/
        flag = 1;
        for(j=1;j<n;j++)            /*找出第i行中的最大元素的位置A[i][max]*/
        {
           if(A[i][j]>A[i][max]) max = j;
        }
        for(k=0;k<n;k++)
           if(A[i][max] == A[i][k] && max != k){flag = 0;break;}
        if(flag == 1)
        for(k=0;k<m;k++)                /*判断A[i][max]是否是本列中最小的*/
        {
          if(A[k][max]<=A[i][max] && k!=i)  /*不是最小元素，因此A[i][max]不是鞍点*/
          {
            flag = 0;
            break;
          }
        }
        if(flag == 1)                /*找到鞍点，用x,y返回，程序结束返回1*/
        {
            *x = i;
            *y = max;
            return 1;
        }
       }

       return 0;             /*没有找到鞍点，返回0*/

}

main()
{
    int A[5][5],i,j,x,y;
    printf("Please input some digit into the 5*5 matrix\n");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        scanf("%d",&A[i][j]);
    if(getSaddlePoint (&x,&y,A,5,5))
        printf("\nSaddlePoint is at (%d,%d)",x+1,y+1);
    else
        printf("\nThere is no in the matrix\n");
       getche();
}

