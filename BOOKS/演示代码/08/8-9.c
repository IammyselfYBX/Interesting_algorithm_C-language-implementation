#include "stdio.h"
#include "math.h"

int getResult(float *x1,float *x2,float *x3 ,int L,float accuracy)
{
   float new_x1=*x1,new_x2=*x2,new_x3=*x3;
   float old_x1=100,old_x2=100,old_x3=100;
   int count=0;
   while((fabs(new_x1-old_x1)>accuracy || fabs(new_x2-old_x2)>accuracy
        || fabs(new_x3-old_x3)>accuracy)&&count<L)
   {
        old_x1 = new_x1;
        old_x2 = new_x2;
        old_x3 = new_x3;
        new_x1 = 0.1*old_x2+0.2*old_x3+0.72;
        new_x2 = 0.1*old_x1+0.2*old_x3+0.83;
        new_x3 = 0.2*old_x1+0.2*old_x2+0.84;
        count++;
   }
   if((fabs(new_x1-old_x1)>accuracy && fabs(new_x2-old_x2)>accuracy
        && fabs(new_x3-old_x3)>accuracy))
        return 0;
    else
    {
        *x1 = new_x1;
        *x2 = new_x2;
        *x3 = new_x3;
        return 1;
    }
}

main()
{
    float x1,x2,x3,accuracy;
    int L;
    printf("Please input initial value of x1,x2,x3\n");        /*输入迭代初值*/
    scanf("%f %f %f",&x1,&x2,&x3);
    printf("Please input the accuracy\n");                /*输入迭代精度*/
    scanf("%f",&accuracy);
    printf("Please input the limitation for counting\n");    /*输入迭代上限*/
    scanf("%d",&L);
    if(getResult(&x1,&x2,&x3,L,accuracy))
        printf("x1 = %f;x2 = %f;x3 = %f\n",x1,x2,x3);    /*输出结果*/
    else
        printf("Please adjust the accuracy or limitation\n");    /*本次计算失败*/
    getche();
}

