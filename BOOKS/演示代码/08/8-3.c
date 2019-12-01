#include "stdio.h"
#include "math.h"
float func(float x)
{
    return pow(x,3)+2*x-1;
}

float ING(float a,float b)
{
    return ((b-a)/6)*(func(a)+4*func((a+b)/2)+func(b));
}

main()
{
    float a,b;
    printf("Please input the low & high limitation and the accuracy\n");
    printf("Low limitation:");
    scanf("%f",&a);
    printf("High limitation:");
    scanf("%f",&b);
    printf("The result of integration is %f",ING(a,b));
    getche();
}

