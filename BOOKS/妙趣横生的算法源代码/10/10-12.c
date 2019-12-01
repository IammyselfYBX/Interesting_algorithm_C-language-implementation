#include "stdio.h"
#include "math.h"
func(int low,int high)
{
    int i;
    double x,y;
    for(i=low;i<=high;i++)
    {
        x=sqrt(i+100);
        y=sqrt(i+168);
        if(x*x==i+100&&y*y==i+168)
          return i;
    } 
     return 0;
}

main()
{
    int i;
    i =  func(1,10000);  /*在0~10000范围内寻找该数*/
    if(i)
        printf("%d add 100 or add 168 equal a perfect square number\n",i);
    else
        printf("There is no answer in the area of 1~10000\n");
    getch();
}
