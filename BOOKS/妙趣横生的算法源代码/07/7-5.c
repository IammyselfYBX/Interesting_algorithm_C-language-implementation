#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef  char ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

void initStack(sqStack *s)
{
    /*内存中开辟一段连续空间作为栈空间，首地址赋值给s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);     /*分配空间失败*/
    s->top = s->base;       /*最开始，栈顶就是栈底*/
    s->stacksize = STACK_INIT_SIZE;   /*最大容量为STACK_INIT_SIZE */
}
void Push(sqStack *s, ElemType e){
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

void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

int StackLen(sqStack s){
    return (s.top - s.base) ; 
}

main()
{
    ElemType c;
    sqStack s1;
    sqStack s2;
    int len,i,j,sum = 0;
    initStack(&s1);  /*创建一个栈s1，用来存放二进制字符串*/

    printf("Please input a binary number and type '#' for end\n");
    /*输入0/1字符表示的二进制数，以#结束*/
    scanf("%c",&c);
    while(c!='#')
    {
        if(c=='0' || c=='1')
            Push(&s1,c); 
        scanf("%c",&c);
    }
    initStack(&s2);  /*创建一个栈s2，用来存放八进制字符串*/
    len = StackLen(s1);  /*得到栈中的元素个数，即二进制数的长度*/
    for(i=0;i<len;i=i+3){
        for(j=0;j<3;j++){
             Pop(&s1,&c);  /*取出栈顶元素*/
             sum = sum + (c-48) * pow(2,j);  /*转换为八进制数*/
             if(s1.base == s1.top) break;
             }
             Push(&s2,sum+48) ;  /*将八进制数以字符形式压入栈中*/
             sum = 0;

          }

    printf("The Octal from is \n") ;
    while(s2.base != s2.top ){ /*输出八进制栈的内容*/
       Pop(&s2,&c);
       printf("%c",c);
    }
    getche();

}