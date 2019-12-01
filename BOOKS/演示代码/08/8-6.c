#include "stdio.h"
#include "math.h"

double NewtonFun(double x)
{
    return x-(x-exp(-x))/(1+x);
}

double getResult(double x1,double accuracy)
{
   double x2 = 0.0;
   x2 = NewtonFun(x1);
   while(fabs(x2-x1)>=accuracy)
   {
        x1 = x2;
        x2 = NewtonFun(x1);
   }
   return x2;
}

main()
{
    double x1,accuracy;
    printf("Please input the initial value\n");        /*输入迭代初值*/
    scanf("%lf",&x1);
    printf("Please input accuracy\n");            /*输入迭代精度*/
    scanf("%lf",&accuracy);
    printf("The result of function is %lf\n",getResult(x1,accuracy));
    getche();
}

