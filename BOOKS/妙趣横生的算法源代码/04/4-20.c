#include "stdio.h"
int Day(int year ,int month,int date)
{
    int months[13]={0,31,0,31,30,31,30,31,31,30,31,30,31} ,i,days=0;
    /*ÅĞ¶ÏÊÇ·ñÊÇÈòÄê*/
    if((year % 4 == 0 && year % 100 !=0)||(year % 400 ==0 ))
        months[2]=29;
    else
        months[2]=28;
    for(i=1;i<month;i++)
     days = days + months[i];
    days = days + date;
    return days;
}

main()
{
    printf("The days of 6th Match 2009 is %d\n",Day(2009,3,6));
    getche();
}

