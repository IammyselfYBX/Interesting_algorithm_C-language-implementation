#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef  int ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;
/*初始化栈*/
void initStack(sqStack *s)
{
    /*内存中开辟一段连续空间作为栈空间，首地址赋值给s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);				/*分配空间失败*/
    s->top = s->base;				/*最开始，栈顶就是栈底*/
    s->stacksize = STACK_INIT_SIZE; 	/*最大容量为STACK_INIT_SIZE */
}
/*入栈操作，将e压入栈中*/
void Push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
    /*栈满，追加空间*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);                                /*存储分配失败*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT;        /*设置栈的最大容量*/
    }
    *(s->top) = e;                                    		 /*放入数据*/
        s->top++;
}
/*出栈操作，用e将栈顶元素返回*/
void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

int f(int n)
{
    int r = 1, e;
    sqStack stack;
    initStack(&stack);				/*初始化栈*/
        while(n!=0){
            Push(&stack,n);			/*保存现场n*/
            n = n/2;
        }
        while(stack.top!=stack.base)
        {
            Pop(&stack,&e);
            r = r * e;
        }
        return r;
}

main()
{
    printf("The result for conversion of recursion to non recursion is\n");
    printf("f(5)=%d \n",f(5));
    getche();
}
