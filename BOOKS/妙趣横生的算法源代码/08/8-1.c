#include "stdio.h"
#include "math.h"

double func(double x)
{
    if(x!=0)
        return sin(x)/x;
    else
        return 1.0;
}
double ING(double a,double b,double e)
{
    double T1=0.0,T2=0.0,S=0.0,h,x;
    int flag;
    h = b - a;
    T1 = h/2*(func(a)+func(b));
    do{
        S = 0;
        x = a + h/2;
        while(x<b){
            S = S + func(x);
            x = x + h;
        }
        T2 = T1/2 + h/2*S;
        if(fabs(T1-T2)>=e){
             h = h/2;
             T1 = T2;
             flag = 1;
        }
        else flag = 0;
        }
       while(flag);
    return T2;
}

main()
{
    double a,b,e;
    printf("Please input the low & high limitation and the accuracy\n");
    printf("Low limitation:");
    scanf("%lf",&a);
    printf("High limitation:");
    scanf("%lf",&b);
    printf("The accuracy:");
    scanf("%lf",&e);
    printf("The result of integration is %lf",ING(a,b,e));
    getche();
}

