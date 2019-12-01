#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
/*定义堆栈*/
typedef  char ElemType;
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
    if(!s->base) exit(0);					/*分配空间失败*/
    s->top = s->base;					/*最开始，栈顶就是栈底*/
    s->stacksize = STACK_INIT_SIZE;		/*最大容量为STACK_INIT_SIZE */
}
/*入栈操作，将e压入栈中*/
void Push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
    /*栈满，追加空间*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);								/*存储分配失败*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT;		/*设置栈的最大容量*/
    }
    *(s->top) = e;									/*放入数据*/
        s->top++;
}
/*出栈操作，用e将栈顶元素返回*/
void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

/*计算堆栈s当前的长度*/
int StackLen(sqStack s){
    return (s.top - s.base) ; 
}

void ADD(sqStack *s1,sqStack *s2,sqStack *s3)
{
char a1,a2,a3,c=0; 				/*a1,a2分别存放从堆栈s1,s2中取出的（数据）元素，
a3=a1+a2,c中存放进位*/
    while(StackLen(*s1)!=0 && StackLen(*s2)!=0)
    {
         Pop(s1,&a1);					/*取出s1栈的栈顶元素给a1*/
         Pop(s2,&a2);					/*取出s2栈的栈顶元素给a2*/
         a3 = (a1-48) + (a2-48) + c + 48;		/*相加*/
         if(a3>'9')
         {
               a3 = a3 - '9' + 47;			/*产生进位的情况*/
               c = 1;
          }
          else
              c = 0;					/*不产生进位*/
         Push(s3,a3);					/*将结果入栈s3*/
     }
     if(StackLen(*s1)!=0)					/*栈s1不为空的情况*/
     {
        while(StackLen(*s1)!=0)
        {
           Pop(s1,&a1);					/*取出s1栈的栈顶元素给a1*/
           a3 = a1 + c ;					/*与进位标志c相加*/
           if(a3>'9')
           {
               a3 = a3 - '9' + 47;			/*产生进位的情况*/
               c = 1;
           }
          else
              c = 0;					/*不产生进位*/
           Push(s3,a3);					/*将结果入栈s3*/
        }
     }
     else if(StackLen(*s2)!=0)				/*栈s1不为空的情况*/
     {
        while(StackLen(*s2)!=0)
        {
           Pop(s2,&a2);					/*取出s1栈的栈顶元素给a1*/
           a3 = a2 + c;					/*与进位标志c相加*/
           if(a3>'9')
           {
               a3 = a3 - '9' + 47;			/*产生进位的情况*/
               c = 1;
           }
          else
              c = 0;					/*不产生进位*/
           Push(s3,a3);					/*栈s1不为空的情况*/
        }
     }
     if(c==1)
        Push(s3,'1');					/*如果最后有进位，将字符’1’入栈s3*/
}

main()
{
    char e;
    sqStack s1,s2,s3;
    initStack(&s1);							/*初始化堆栈s1，存放加数*/
    initStack(&s2);							/*初始化堆栈s2，存放加数*/
    initStack(&s3);							/*初始化堆栈s3，存放结果*/
    printf("Please input the first integer\n");		/*输入第一个任意长整数，按”#”结尾*/
    scanf("%c",&e);
    while(e!='#')
    {
       Push(&s1,e);							/*将加数（字符串）入栈s1*/
       scanf("%c",&e);
    }
    getchar();								/*接收回车符*/
    printf("Please input the second integer\n");		/*输入第二个任意长整数，按”#”结尾*/
    scanf("%c",&e);
    while(e!='#')
    {
       Push(&s2,e);							/*将加数（字符串）入栈s2*/
       scanf("%c",&e);
    }
    ADD(&s1,&s2,&s3);						/*加法运算，将结果存放在s3中*/
    printf("The result is\n");
    while(StackLen(s3)!=0)					/*输出结果，打印在屏幕上*/
    {
        Pop(&s3,&e);
        printf("%c",e);
    }
    getche();
}
