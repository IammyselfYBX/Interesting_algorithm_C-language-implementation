#include "stdio.h"

typedef struct BiTNode{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

/*创建一棵二叉树*/
CreatBiTree(BiTree *T , int *level1 , int level2){
    char c;

    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));           /*创建根结点*/
        (*T)->data = c;                                    /*向根结点中输入数据*/


        if(*level1<level2) {*level1 = level2;}


        CreatBiTree(&((*T)->lchild),&(*level1),level2+1);     /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild),&(*level1),level2+1);     /*递归地创建右子树*/
    }
}


int JusticCompleteBiTree(BiTree T,int level ,int n,int flag){
    if(!T){
        return 1;
        }
    if(level == n)
    {

       if(T->lchild == NULL && T->rchild != NULL) return 0;

       if(flag == 0){/*同层的前面的结点无空指针*/
            if(T->rchild == NULL) flag = 1; /*出现空指针*/
            }
            else if(flag == 1){  /*同层的前面的结点有空指针*/
                if(T->lchild!=NULL || T->rchild!=NULL)  return 0;
            }
    }
     if(level != n &&level !=n+1)
     {
        if(T->lchild == NULL || T->rchild == NULL) return 0;
     }
    if(!JusticCompleteBiTree(T->lchild,level+1,n,flag)) return 0;
    if(!JusticCompleteBiTree(T->rchild,level+1,n,flag)) return 0;
    return 1;
}


main()
{
    BiTree T;
    int level1 = 0;
    printf("Please type some character to creat a binary tree\n");
    CreatBiTree(&T, &level1,0);
    if(JusticCompleteBiTree(T,0,level1-1,0))  printf("It is a complete binary tree\n");
    else  printf("It is NOT a complete binary tree\n");
    getche();


}
