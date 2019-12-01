#include <string.h> 
#include <stdio.h> 

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

/*遍历二叉树，得到叶结点的个数*/
getLeaves(BiTree T,int *count){
    if(T->lchild==NULL && T->rchild==NULL && T!=NULL){   /*访问到叶结点*/
        *count = *count + 1;
    }
    if(T){
        getLeaves(T->lchild,count);  /*先序遍历T的左子树*/
        getLeaves(T->rchild,count);  /*先序遍历T的右子数*/
    }
}

main()
{
   int count = 0;
   BiTree T = NULL;			/*最开始T指向空*/
   CreatBiTree(&T);			/*创建二叉树*/
   getLeaves(T,&count); 		/*遍历二叉树，得到叶结点的个数，用count返回叶结点的个数*/
   printf("The number of leaves of BTree are %d\n",count);
   getche();
}
