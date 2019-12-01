#include "stdio.h"

typedef struct QNode{     /*定义队列结点类*/
    char data;
    struct QNode *next;
} QNode , *QueuePtr;

typedef struct{                /*定义一个链队列*/
    QueuePtr front;         /*队头指针*/
    QueuePtr rear;            /*队尾指针*/
}LinkQueue;

initQueue(LinkQueue *q){
    /*初始化一个空队列*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*创建一个头结点，队头队尾指针                                                                指向该结点*/
    if( !q->front) exit(0);            /*创建头结点失败*/
    q->front->next = NULL;        /*头结点指针域置NULL*/
}

EnQueue(LinkQueue *q, char e){        /*入队列操作*/
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));    /*创建一个队列元素结点*/
    if( !q->front) exit(0);                    /*创建头结点失败*/
    p->data = e;                        /*将元素e入队列*/
    p->next = NULL;                    /*修改队尾指针*/
    q->rear ->next = p;
    q->rear = p;
}
DeQueue(LinkQueue *q, char *e){
    /*如果队列q不为空，删除q的队头元素，用e返回其值*/
    QueuePtr p;
    if(q->front == q->rear) return;  /*队列为空，返回*/
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;  /*如果队头就是队尾，则修改队尾指针*/
    free(p);
}


printTriangle(int n){
    LinkQueue q;
    char e,a,b ;
    int i,j;
    initQueue(&q);          /*初始化队列*/
    printf("Input the the charecter(+/-) of the row.1\n");
    for(i=0;i<n;i++){       /*输入第一行的符号，并入队列*/
       scanf("%c",&e);
       EnQueue(&q,e);
       }

    printf("The charecter triangle is like\n");
     for(i=0;i<n;i++){           /*控制符号三角的行数*/
        for(j=0;j<i;j++)
            printf(" ");           /*控制输出格式，打印成倒三角形状*/
        DeQueue(&q,&a);         /*出队列，打印每行的第一个符号*/
        printf("%c ",a);
        for(j=0;j<n-i-1;j++)    /*控制输出每一行，第i行输出n-i个符号*/
        {
           DeQueue(&q,&b);      /*出队列*/
           printf("%c ",b);
           if(a == b)  EnQueue(&q,'+'); /*向队尾插入新元素*/
           else EnQueue(&q,'-');
           a = b;
        }
        printf("\n");    /*控制输出格式，打印成倒三角形状*/
    }
}

main()
{
    int n;
    printf("Please input the number of '+' or '-' of the row.1 \n");
    scanf("%d",&n);
    getchar();
    printTriangle(n);
    getche();
}
