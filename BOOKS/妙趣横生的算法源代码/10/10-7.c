#include <stdio.h>

int arrayMaxVal(int array[],int n)
{
  if(n == 1) return array[0];
   if (array[0]>=arrayMaxVal(array+1,n-1))
        return array[0];
   else
         return  arrayMaxVal(array+1,n-1);
}

main()
{
    int array[]={1,2,13,11,7,9,3},max;
    max = arrayMaxVal(array,7);
    printf("The max elem in the array is %d\n",max);
    getche();
}
