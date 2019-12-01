#include "stdio.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10


typedef char ElemType;   /*将char类型定义为ElemType*/

typedef struct QNode{     /*定义队列结点类*/
    ElemType data;
    struct QNode *next;
} QNode , *QueuePtr;

typedef struct{      /*定义一个链队列*/
    QueuePtr front;   /*队头指针*/
    QueuePtr rear;    /*队尾指针*/
}LinkQueue;

typedef struct{        /*定义一个栈类型*/
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;


initQueue(LinkQueue *q){
    /*初始化一个空队列*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*创建一个头结点，队头队尾指针                                                                指向该结点*/
    if( !q->front) exit(0);     /*创建头结点失败*/
    q->front->next = NULL;     /*头结点指针域置NULL*/
}

EnQueue(LinkQueue *q, ElemType e){      /*入队列操作*/
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));  /*创建一个队列元素结点*/
    if( !q->front) exit(0);     /*创建头结点失败*/
    p->data = e;                /*将元素e入队列*/
    p->next = NULL;             /*修改队尾指针*/
    q->rear ->next = p;
    q->rear = p;
}
DeQueue(LinkQueue *q, ElemType *e){
    /*如果队列q不为空，删除q的队头元素，用e返回其值*/
    QueuePtr p;
    if(q->front == q->rear) return;  /*队列为空，返回*/
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;  /*如果队头就是队尾，则修改队尾指针*/
    free(p);
}

initStack(sqStack *s)
{
    /*内存中开辟一段连续空间作为栈空间，首地址赋值给s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);     /*分配空间失败*/
    s->top = s->base;       /*最开始，栈顶就是栈底*/
    s->stacksize = STACK_INIT_SIZE;   /*最大容量为STACK_INIT_SIZE */
}

Push(sqStack *s, ElemType e){        /*入栈操作*/
    if(s->top - s->base >= s->stacksize){
    /*栈满，追加空间*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);   /*存储分配失败*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT; /*设置栈的最大容量*/
    }
    *(s->top) = e;  /*放入数据*/
        s->top++;
}

Pop(sqStack *s , ElemType *e){   /*出栈操作*/
    if(s->top == s->base) return;  /*将栈顶元素弹出*/
    *e = *--(s->top);              /*修改栈顶指针*/
}

int StackLen(sqStack s){     /*获得栈s的大小*/
    return (s.top - s.base) ; 
}


main()
{
    sqStack s;
    LinkQueue q;
    ElemType e,r1,r2;
    int flag = 1, i, len;

    initQueue(&q);  /*初始化一个队列*/
    initStack(&s);  /*初始化一个栈*/
    printf("Please input a string ,type '@' for end\n");
    scanf("%c",&e);
    while(e != '@'){       /*输入待判断的字符序列*/
        Push(&s,e);
        EnQueue(&q,e);
        scanf("%c",&e);
    }

    len =  StackLen(s)/2;  /*获得字符序列的长度*/

    for(i=0;i<len;i++)
    {
        Pop(&s,&r1);     /*出栈操作，由r1将栈顶元素返回*/
        DeQueue(&q,&r2); /*出队列操作，由r2将队头元素返回*/
        if(r1 != r2) { flag = 0; break;}
    }
    if(flag == 1)printf("It is a circle string.\n");
    else printf("It is not a circle string.\n") ;
    getche();
}

