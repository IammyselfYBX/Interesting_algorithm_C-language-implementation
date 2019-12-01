#include <string.h> 
#include <stdio.h> 

void PrintMulTab() ;

int main()
{
    PrintMulTab() ;
    getchar();
}

void PrintMulTab()
{
    int i,j;
    for (j=1;j<=9;j++)
    {
      for(i=1;i<=j;i++)
        printf("%d*%d=%d ",i,j,j*i);
      printf("\n");
    }
}
