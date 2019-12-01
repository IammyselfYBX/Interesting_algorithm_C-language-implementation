#include "stdio.h"
# define MAXSIZE 10
typedef struct{
    int * base;
    int length;
}sqlist ;

reverseSQ(sqlist *l){
    int low = 0 , high = l->length - 1;
    int buf , i;
    for(i=0;i<l->length/2;i++)
    {
        buf = l->base[low] ;
        l->base[low] = l->base[high];
        l->base[high] = buf;
        low++;
        high--;
    }
}

main()
{
    sqlist l;
    int a , i = 0;
    /*创建一个顺序表*/
    l.base = (int *)malloc(sizeof(int)*MAXSIZE);
    l.length = 0;

    /*输入数据*/
    printf("Please input below 10 integer into the sqlist\n") ;
    printf("Type -1 for stopping input\n");
    scanf("%d",&a);
    while(a != -1 && i<=9)
    {
        l.base[i] = a;
        l.length++;
        i++;
        scanf("%d",&a);
    }

    /*输出原顺序表中的数据*/
    printf("The contents of the sqlist are\n");
    for(i=0;i<l.length;i++)
         printf("%d ",l.base[i]);
     printf("\n");

    reverseSQ(&l);    /*就地逆置顺序表*/


    /*输出逆置后的顺序表中的数据*/
    printf("The contents of the reversed sqlist are\n");
    for(i=0;i<l.length;i++)
        printf("%d ",l.base[i]);
       getche();

}