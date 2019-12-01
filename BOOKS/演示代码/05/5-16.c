#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>

double getPI(int n);

void main()
{
    double PI;
    int n;
    printf("Please enter the number of random points for test\n");
    scanf("%d",&n);
    PI=getPI(n);
    printf("The similar value of PI is\n%f\n",PI);
    getchar();
}

double getPI(int n)
{
     int inCircle=0;
     float x,y;
     int count=n;
     while(count)
    {
        x=random(101);
        y=random(101);
        if(x*x+y*y<=10000)
            inCircle++;
        count--;
     }
     return 4.0*inCircle/n;
}

