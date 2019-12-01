#include "stdio.h"

int getAge(int n)
{
    if(n == 1) return 10;           /*第一个人十岁*/
    else    return getAge(n-1)+2;    /*第n个人的年龄比第n-1人的年龄大2岁*/
}

main()
{
    printf("Age of the first  person is %d\n",getAge(1));
    printf("Age of the second person is %d\n",getAge(2));
    printf("Age of the third  person is %d\n",getAge(3));
    printf("Age of the forth  person is %d\n",getAge(4));
    printf("Age of the fifth  person is %d\n",getAge(5));
    getche();
}
