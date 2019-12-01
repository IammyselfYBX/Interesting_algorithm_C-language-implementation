#include "stdio.h"

/*链表结点定义*/
typedef struct node{
    int number;  /*编号*/
    int psw;    /*个人密码*/
    struct node *next;
} LNode,*LinkList;


void insertList(LinkList *list,LinkList q,int e1,int e2){
    LinkList p;
    p=( LinkList)malloc(sizeof(LNode));
    p->number = e1;
    p->psw = e2;
    if(!*list){
    *list=p;
    p->next=NULL;
    }
    else{
        p->next=q->next;
        q->next=p;
    }    
}



CreatJoseph(LinkList *jsp , int n)
{
    LinkList  q = NULL , list = NULL;
    int i ,  e2;
     printf("Please input the password for people in the Joseph circle\n");
    for(i=0;i<n;i++){
        scanf("%d",&e2);
        insertList(&list,q,i+1,e2);   /*向q指向的结点后面插入新的结点*/
        if(i == 0) q = list;   /*第一次之生成头结点，q也指向头结点*/
        else q = q->next;        /*q指向下一结点*/
        }
    q->next = list; /*形成循环链表*/

    *jsp = list;  //返回
}


exJoseph(LinkList *jsp, int m)
{
    LinkList p ,q;
    int i;
    q = p = *jsp ;
    while(q->next != p) q=q->next;  /*q指向p的前一个结点*/

    printf("The order of a column is\n") ;
    while(p->next != p){
    for(i=0;i<m-1;i++)
    {                    /*p指向要删除的结点,q指向p的前一个结点*/
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("%d ",p->number);
    m = p->psw;
    free(p);
    p = q->next;
    }
    printf("\nThe last person in the circle is %d\n",p->number);    /*打印出最后留在队中的人的编号*/
}

main()
{
     LinkList jsp;
     int n , m;
     printf("Please input number of the people in the Joseph circle\n");
     scanf("%d",&n) ;
     CreatJoseph(&jsp, n);
     printf("Please input the first maximum number\n");
     scanf("%d",&m) ;
     exJoseph(&jsp,m) ;
     getche();
}
