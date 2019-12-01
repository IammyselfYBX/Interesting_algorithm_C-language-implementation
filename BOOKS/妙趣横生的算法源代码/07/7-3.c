#include "stdio.h"

/*定义int为ElemType类型*/
typedef int ElemType;

/*定义链表的结点类型*/
typedef struct node{
    ElemType data;   /*数据域*/
    struct node *next;  /*指针域*/
}LNode,*LinkList;

/*创建一个长度为n的链表，并输入数据*/
LinkList GreatLinkList(int n){
    LinkList p,r,list=NULL;
          ElemType e;
        int i;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;
        if(!list)
            list=p;
        else
            r->next=p;
        r=p;
    }
    return list;
}

/*向链表中插入结点，并向该结点的数据域中存放数据e*/
void insertList(LinkList *list,LinkList q,ElemType e){
LinkList p;
    p=( LinkList)malloc(sizeof(LNode));
    p->data=e;
    if(!*list){
    *list=p;
    p->next=NULL;
    }
    else{
        p->next=q->next;
        q->next=p;
    }    
}

void insertNode(LinkList *q1,LinkList *q2,LinkList *p,LinkList *l2){
     if(*q1 == *q2)
     {
         (*p)->next = *q2;
         *l2 = *q2 = *q1 = *p;

     }
     else
     {
        (*q2)->next = *p;
        (*p)->next = *q1;
        (*q2) = (*q2)->next;
     }
}

void MergeLink(LinkList l1, LinkList l2 ,LinkList *l3)
{
    /*将链表l1,l2有序归并，l3指向归并后的新链表*/
    LinkList p,q1,q2;
    q1 = q2  = l2; /*l3指向l2*/
    p = l1;
    while(p!=NULL && q1!=NULL){
        if(p->data >= q1->data) {
        q2 = q1;
        q1 = q1->next;
        }
        else{
            l1 = l1->next ;
            insertNode(&q1,&q2,&p,&l2);     /*将p指向的结点茶道q2之前q1之后*/
           // q2 = q2->next;
            p = l1;
        }
    }

    if(q1 == NULL) q2->next = p;

    *l3 = l2;


}

main()
{
    ElemType e;
    LinkList  l1,l2,l3,q;

    printf("Please input the contents of Link1\n");
    q=l1=GreatLinkList(1);   /*创建一个链表结点，q和l指向该结点*/

    scanf("%d",&e);
    while(e)             /*循环地输入数据，同时插入新生成的结点*/
    {
      insertList(&l1,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }

    printf("Please input the contents of Link2\n");
    q=l2=GreatLinkList(1);   /*创建一个链表结点，q和l指向该结点*/

    scanf("%d",&e);
    while(e)             /*循环地输入数据，同时插入新生成的结点*/
    {
      insertList(&l2,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }

    MergeLink(l1,l2,&l3);  /*合并l2,l2并用l3指向合并后的链表*/

    q = l3;

    printf("The merge of link1 and link 2 is\n");
    while(q)            /*打印出合并后的链表*/
    {
        printf("%d ",q->data) ;
        q = q->next;
    }
    getche();


}
