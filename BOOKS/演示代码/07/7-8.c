#include "stdio.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;   /*将char类型定义为ElemType*/
typedef struct{        /*定义一个栈类型*/
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;


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


void  translate(ElemType e, sqStack *s){
     ElemType c , a;
     sqStack ss1;
    if(e>=97 && e<=122 )  printf("%c",e);
    else if(e == 'A') printf("%s","sae");
    else if(e == 'B') printf("%s","tsaedsae");
    else if(e == '(')
    {

        initStack(&ss1); /*初始化栈ss1，用来将括号里面的内容从栈中取出*/
        Pop(&(*s),&c);  /*注意*s相当于主函数中的s*/
        a = c; /*保留括号后的第一个元素*/
        Pop(&(*s),&c); 
        while(c!=')'){
            Push(&ss1,a);
            Push(&ss1,c);
            Pop(&(*s),&c); 
       }
        Push(&ss1,a);        /*并按语法规定排列后从右至左进入一个新栈ss1*/
       while(StackLen(ss1))  /*翻译括号里的内容*/
       {
         Pop(&ss1,&c);       /*取出ss1中的元素c*/
         translate(c,&ss1);  /*递归地调用函数 translate对元素c进行翻译*/
       }
    }
}



main()
{
    ElemType e;
    sqStack s1,s2;
    initStack(&s1);   /*初始化栈s1*/

    printf("Please input Devil language:\n");
    scanf("%c",&e);

    while(e != '#')
    {
        if(e=='A' || e=='B' || (e>=97 && e<=122) || e=='('|| e==')')
        {   /*输入的魔王语言合法*/
            Push(&s1,e);  /*入栈*/

        }
        scanf("%c",&e);
    }


    initStack(&s2);  /*初始化栈s2*/
    while(StackLen(s1))
    {
        Pop(&s1,&e);
        //printf("%c\n",e);
        Push(&s2,e);  /*将魔王语言从右至左入栈s2*/
    }

    printf("The mankind language is:\n");
      while(StackLen(s2))
      {
        Pop(&s2,&e);
        translate(e,&s2) ;
      }

     getche();
}



