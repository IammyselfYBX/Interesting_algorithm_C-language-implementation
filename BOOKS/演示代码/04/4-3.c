#include <stdio.h>
int main(void) 
{ 
    int score;
    printf("Please input the score\n");
    scanf("%d",&score);
    if(score<80)
        if(score<70)
            if(score<60)
                 printf("E\n");
            else
                printf("D\n");
         else
                printf("C\n");
     else
        if(score<90)
            printf("B\n");
        else
            printf("A\n");
    getchar();
    return 0;
}

