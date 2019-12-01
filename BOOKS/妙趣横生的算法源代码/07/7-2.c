/******************************************Dynamic Sort*************************************************/
#include <string.h> 
#include <stdio.h> 
#include <malloc.h>

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

/*向链表中插入结点*/
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



/*基于链表的冒泡排序算法*/
void Sort(LinkList q)
{
    LNode *p=q;
    int t,i,j,k=0;
    while(p) {k++; p=p->next;}
    p=q;
    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k-i-1;j++)
        {
            if(p->data>p->next->data)
            {
              t=p->data;
              p->data=p->next->data;
              p->next->data=t;
            }
            p=p->next;
        }
    p=q;
    }

}

/*打印出排序后的新链表中的内容*/
void Print(LinkList q)
{
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}

/*主函数*/
main()
{
    ElemType e;
    LinkList  l,q;    /*定义一个链表l*/
    printf("Please input some integer digit and type 0 for end\n");
    q=l=GreatLinkList(1);   /*创建一个链表结点，q和l指向该结点*/

    scanf("%d",&e);
    while(e)             /*循环地输入数据，同时插入新生成的结点*/
    {
      insertList(&l,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }


    Sort(l);
    Print(l);
    getche();
}

