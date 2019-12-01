#include "stdio.h"

typedef struct node{
    int data;
    int freq;
    struct node *prior;
    struct node *next;
}dbLNode,*dbLinkList;

/*创建一个双向链表，返回它的头指针*/
dbLinkList GreatdbLinkList(int n){
   dbLinkList p,r,list=NULL;
   int e;
   int i;
    list = (dbLinkList)malloc(sizeof(dbLNode));  /*创建头结点head,头结点中不存放内容*/
    list->next = list->prior = NULL;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p = (dbLinkList)malloc(sizeof(dbLNode));
        p->data = e;
        p->freq = 0;
        p->next = NULL;
        p->prior = NULL;
        if(!list->next) {
            list->next = p;      /*第一个结点*/
            p->prior = list;
            }
        else{
            r->next = p;   /*双向连接下面的结点*/
            p->prior = r;
            }

        r = p;
    }
    return list;
}

/*访问双向链表中指定的结点，并调整结点次序*/
visit(dbLinkList *l,int x){
    dbLinkList p = *l, q, r, s;
    p = p->next;   /*p指向第一个结点*/
    while(p->data != x && p!=NULL)p = p->next;
    if(p == NULL) {printf("Input error!\n");return;}
    p->freq ++;
    printf("Visiting this node\n");
    while((p->prior)!=*l && p->freq > p->prior->freq)
    {

           /*实现双向链表结点的交换*/
            q = p->prior;
            r = p->next;
            s = p->prior->prior;
            p->prior = q->prior;
            p->next = q;
            q->prior = p;
            q->next = r;
            r->prior = q;
            s->next = p;
    }

}

TransdbLinkList(dbLinkList l)
{   /*遍历整个双向链表,并打印出每个结点中的数据和访问频度*/
    l = l->next;
    while(l!=NULL){
        printf("(data:%d ,freq:%d)--> ",l->data,l->freq);
        l = l->next;
        }

     printf("X\n\n");

}

main()
{
   dbLinkList l;
   int d;
   printf("Input five integer to creat a doubly link list\n");
   l = GreatdbLinkList(5);
   TransdbLinkList(l);

   printf("Please input the data that you want to vist\n");

   scanf("%d",&d);
   while(d!=0){
   visit(&l,d);
   TransdbLinkList(l);
   scanf("%d",&d);
   }
   getche();
}

