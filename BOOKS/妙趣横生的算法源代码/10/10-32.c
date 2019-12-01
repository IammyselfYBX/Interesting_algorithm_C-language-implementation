#include "stdio.h"

typedef char ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode *next;
} QNode , *QueuePtr;
typedef struct{
    QueuePtr front;   //队头指针
    QueuePtr rear;    //队尾指针
}LinkQueue;

initQueue(LinkQueue *q){
    /*初始化一个空队列*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*创建一个头结点，队头队尾指针                                                                指向该结点*/
    if( !q->front) exit(0);     /*创建头结点失败*/
    q->front->next = NULL;     /*头结点指针域置NULL*/
}

EnQueue(LinkQueue *q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));  /*创建一个队列元素结点*/
    if( !q->front) exit(0);     /*创建头结点失败*/
    p->data = e;
    p->next = NULL;
    q->rear ->next = p;
    q->rear = p;
}

int getQueueLen(LinkQueue *q)
{
    QNode *p;
    int count = 0;
    p = q->front;
    while(p!=q->rear)
    {
        p = p->next;
        count++;
    }
    return count;
}

main()
{
    LinkQueue  q;
    char e;
    initQueue(&q);					/*初始化一个队列q*/
    printf("Please input a string into a queue\n");
    scanf("%c",&e);
    while(e!='@'){
        EnQueue(&q,e);				/*向队列中输入字符串，以@表示结束*/ 
        scanf("%c",&e);
    }
    printf("The length of the Queue is %d\n",getQueueLen(&q));	/*输出队列的长度*/
    getche();
}
