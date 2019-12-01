#include <stdio.h>
int main(void) 
{ 
    int A[2][3]={{1,2,3},{4,5,6}};                 /*初始化矩阵A*/
    int B[3][4]={{1,0,2,3},{4,1,5,6},{6,8,9,0}};      /*初始化矩阵B*/
    int C[2][4]={{0,0,0,0},{0,0,0,0}};
    int i,j,k;
    for(i=0;i<2;i++)
        for(j=0;j<4;j++)
            for(k=0;k<3;k++)
                C[i][j]=C[i][j]+A[i][k]*B[k][j] ;
    printf("The result is\n");
    for(i=0;i<2;i++) {
        for(j=0;j<4;j++)
            printf("%d ",C[i][j]);
       printf("\n");
         }
    return 0;
}

