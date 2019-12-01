#include "stdio.h"

typedef struct BiTNode{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;
/*创建一棵二叉树*/
CreatBiTree(BiTree *T){
    char c;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*创建根结点*/
        (*T)->data = c;    /*向根结点中输入数据*/
        CreatBiTree(&((*T)->lchild));  /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild));  /*递归地创建右子树*/
    }
}

int PreOrderTraverse(BiTree T,int level){
    int l;
    if(T){   /*递归结束条件，T为空*/
        if(T->data=='C')
            return level;
        l = PreOrderTraverse(T->lchild,level+1);  /*先序遍历T的左子树*/
       if(l != 0) return l;
        else
        return PreOrderTraverse(T->rchild,level+1) ;  /*先序遍历T的右子数*/
        }
        return 0;
}

main()
{
   int level = 1;
   BiTree T = NULL;  /*最开始T指向空*/
   CreatBiTree(&T);  /*创建二叉树*/
   /*遍历二叉树，找到包含D字符结点位于二叉树中的层数*/
   printf("C is at level %d in the BITree\n",PreOrderTraverse(T,level) ) ;
   getche();
}
