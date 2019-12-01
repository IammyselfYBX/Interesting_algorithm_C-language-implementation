#include <time.h> 
#include <stdio.h> 
#include <dos.h> 
int main() 
{ 
   clock_t start, end;
   /*程序运行到现在的时间*/
   start = clock(); 
   /*间隔1秒*/
   sleep(1);
   /*程序运行到现在的时间*/
   end = clock(); 
   printf("The time was: %f\n", (end - start) / CLK_TCK); 
   getche();
   return 0; 
}

