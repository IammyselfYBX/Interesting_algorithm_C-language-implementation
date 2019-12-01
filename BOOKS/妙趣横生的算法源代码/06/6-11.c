#include "stdio.h"
int getfish(int init,int n)
{
   int s = init;
   while(n)
   {
        s = 5*s+1 ;
        n--;
   }
   return s;
}

main()
{
    printf("Fish which were gotten by fishers at least are %d",getfish(6,4));
    getche();
}
