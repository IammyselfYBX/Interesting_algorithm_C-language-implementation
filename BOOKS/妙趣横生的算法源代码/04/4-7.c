#include "stdio.h"
#include <stdio.h>
void InputMatrix(int (*a)[4],int ,int );
void OutputMatrix(int (*b)[3],int ,int );
void MatrixTranspose(int (*a)[4],int (*b)[3]);

int main(void)
{ 
    int a[3][4],b[4][3];        /*a 存放原矩阵，b存放a 矩阵的转置矩阵*/
    printf("Please input 3X4 matrix\n");
    InputMatrix(a,3,4);
    MatrixTranspose(a,b);
    printf("The Transposex Matrix is\n");
    OutputMatrix(b,4,3);
    getchar();
   return 0;
}
void InputMatrix(int (*a)[4],int n,int m)
{
   /*输入n*m阶的矩阵     */
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",*(a+i)+j);
}
void OutputMatrix(int (*b)[3],int n,int m)
{
    /* 输出n*m阶矩阵的值     */
     int i,j;
     for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d  ",*(*(b+i)+j));
            printf("\n");
        }
}
void MatrixTranspose(int (*a)[4],int (*b)[3])
{
    /*矩阵的转置运算*/
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<3;j++)
            b[i][j]=a[j][i];
}

