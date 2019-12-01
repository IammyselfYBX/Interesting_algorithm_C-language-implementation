#include <string.h> 
#include <stdio.h> 
#include <math.h>

double getPI(int n);

void main()
{
    int n;
    double PI;
    printf("Please enter accuracy\n");
    scanf("%d",&n);
    PI=getPI(n);
    printf("The similar value of PI is\n%f\n",PI);
    getchar();
}

double getPI(int n)
{
    int div,i=4;
    double b=sqrt(2)/2.0;
    double c=0.0;
    for(div=0;div<n;div++)
    {
        b=sqrt(2.0-2.0*sqrt(1.0-b*b))*0.5;
        i=i*2;
    }
    c=b*i;
    return c;
}

