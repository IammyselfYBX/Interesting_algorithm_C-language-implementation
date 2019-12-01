#include <stdio.h>
move(int n,char x,char y,char z)
{
    if(n==1)
      printf("%c-->%c\n",x,z);
    else
    {
      move(n-1,x,z,y);
      printf("%c-->%c\n",x,z);
      move(n-1,y,x,z);
    }
}
int main(void) 
{ 
    int n;
    printf("input diskes number:\n");
    scanf("%d",&n);                        /*输入盘子数目n*/
    printf("The step to moving %d diskes:\n",n);
    move(n,'A','B','C');                    /*递归调用move，求解盘子的搬运过程*/
    getche();
    return 0;
}

