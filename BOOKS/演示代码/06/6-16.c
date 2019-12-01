#include "stdio.h"
struct player{
  int num;
  int score;
  int rand;
} ;

void  sortScore(struct player psn[],int n)
{
   int i,j;
   struct player tmp;
   for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
    {
        if(psn[j].score>psn[j+1].score)
        {
            tmp = psn[j];
            psn[j] = psn[j+1];
            psn[j+1] = tmp;
        }
    }
}

void setRand(struct player psn[],int n)
{
    int i,j=2;
    psn[0].rand=1;
    for(i=1;i<n;i++)
    {
        if(psn[i].score!=psn[i-1].score )
        {
            psn[i].rand=j;
            j++;
        }
        else
        psn[i].rand=psn[i-1].rand;

    }
}

void  sortNum(struct player psn[],int n)
{
   int i,j;
   struct player tmp;
   for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
    {
        if(psn[j].num>psn[j+1].num)
        {
            tmp = psn[j];
            psn[j] = psn[j+1];
            psn[j+1] = tmp;
        }
    }
}

void sortRand(struct player psn[],int n)
{
   sortScore(psn,n);          /*以分数为关键字排序*/
   setRand(psn,n);           /*按照分数排名次*/
   sortNum(psn,n);          /*按照序号重新排序*/
}

main()
{
   struct player psn[7]={{1,5,0},{2,3,0},{3,4,0},{4,7,0},{5,3,0},{6,5,0},{7,6,0}};
   int i;
   sortRand(psn,7);
   printf("num   score rand  \n");
   for(i=0;i<7;i++)
   {
        printf("%d%6d%6d\n",psn[i].num,psn[i].score,psn[i].rand);
   }
   getche();
}

