#include "stdio.h"
#include <conio.h>
#include <graphics.h>

typedef struct BiTNode{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

CreatBiTree(BiTree *T){
    char c;
    gotoxy(5,5)  ;
    printf("Please input chareter to creat a BiTree\n") ;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*创建根结点*/
        (*T)->data = c;    /*向根结点中输入数据*/
        CreatBiTree(&((*T)->lchild));  /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild));  /*递归地创建右子树*/
    }
}

printTree(BiTree T,int x,int y){
    char e[2] = {'\0','\0'};

    if(T){   /*递归结束条件，T为空*/
          { /*画出一个结点，程序暂停2秒*/
           e[0] = T->data  ;
           circle(x,y,8)  ;
           settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
           outtextxy(x,y,e);
           sleep(2);
           }
        if(printTree(T->lchild,x-(200-y),y+20))  /*先序遍历T的左子树*/
            line(x,y,x-(200-y),y+20);
        if(printTree(T->rchild,x+(200-y),y+20))  /*先序遍历T的右子数*/
             line(x,y,x+(200-y),y+20)   ;
        return 1;
    }
    return 0;
}

main()
{
    BiTree T = NULL;
    int y = 100 ,x = 350;  /*设置二叉树根结点坐标*/
int   GraphDriver = DETECT;  
int GraphMode;
    int color;
    color = RED;
    initgraph( &GraphDriver, &GraphMode, "\\tc\\bgi" );  /* 初始化图形系统，驱动文件"\\tc\\bgi"的路径不能设置错误*/
    setcolor(color);  /*设置图形颜色：红色*/
    CreatBiTree(&T);  /*创建二叉树*/
    printTree(T,x,y);  /*动态显示二叉树创建过程*/
    getche();
    closegraph();
}

