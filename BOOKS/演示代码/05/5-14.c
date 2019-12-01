#include "stdio.h"
main()
{
   int computer , people , spare = 21;
      printf(" -----------------------------------------\n");
      printf(" --------  你不能战胜我,不信试试  --------\n");
      printf(" -----------------------------------------\n\n");
      printf("Game begin:\n\n");
   while(1)
   {
        printf(" ----------  目前还有火柴 %d 根 ----------\n",spare);
        printf("People:") ;
        scanf("%d",&people);
        if(people<1 || people>4 || people>spare)
        {printf("你违规了，你取的火柴数有问题!\n\n");continue;}
        spare = spare - people;
        if(spare == 0){printf("\nComputer win! Game Over!\n"); break;}
        computer =  5 - people;
        spare = spare - computer;
        printf("Computer:%d  \n",computer);
        if(spare == 0){printf("\nPeople win! Game Over!\n"); break;}
   }
}

