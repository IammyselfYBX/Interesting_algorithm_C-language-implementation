#include <stdio.h >
#include "math.h"
main()
{
    double sum = 0;  /*定义双精度变量sum存放结果*/
    int i;
    for(i=1;i<=64;i++)
    sum = sum + pow(2,i-1);    /*累加求和*/
    printf("The number of the grain is \n%f\n",sum);  /*打印出结果*/
}

