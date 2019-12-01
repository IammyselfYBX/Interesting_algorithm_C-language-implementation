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


int match(char e,char c){
    if(e=='(' && c==')')return 1;
    if(e=='[' && c==']')return 1;
    return 0;
}

main()
{
    sqStack s;
    char c , e ;
    initStack( &s ) ;  /*初始化一个空栈*/
    scanf("%c",&c);  /*输入第一个字符*/
    while(c!='#'){   /*'#'为输入的结束标志*/
        if(!StackLen(s))
            Push(&s,c);  /*如果栈为空，则说明输入的是第一个字符，因此保存在栈中*/
        else
        {
             Pop(&s,&e);    /*取出栈顶元素*/
             if(!match(e,c)){  /*将输入的元素与取出的栈顶进行比较，如果匹配不成功*/
                Push(&s,e);   /*先将原栈顶元素重新入栈*/
                Push(&s,c);   /*再将输入的括号字符入栈*/
               }
        }
        scanf("%c",&c);  /*输入下一个字符*/
        }
    if(!StackLen(s))  printf("The brackets are matched\n");  /*如果栈s为空，则括号完全匹配*/
    else  printf("The brackets are not matched\n");   /*如果栈s不为空，则括号不完全匹配*/
    getche();

}

