#include "stdio.h"

typedef int ElemType;

typedef struct node{
    ElemType data;   /*数据域*/
    struct node *next;  /*指针域*/
}Lnode,*LinkList;

LinkList GreatLinkList(int n){
    LinkList p,r,list=NULL;
    ElemType e;
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(Lnode));
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

int LinkListLen(Lnode *head)
{
    Lnode *p = head;
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

main()
{
    LinkList l;
    printf("Please input 10 integer to create a linklist\n");
    l = GreatLinkList(10);      						/*创建10个链结点的单链表*/
    printf("The LinkList includes %d node\n",LinkListLen(l));	/*输出链表的长度*/
    getche();
}
