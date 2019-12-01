#include <string.h> 
#include <stdio.h> 
int count=0; /*计数变量，用来记录八皇后问题的解的个数，它是一个全局变量*/

/***************************************************/
/*notEqual函数为EightQueen函数所调用  */
/*目的是用来判断棋盘的第row行第j列能否*/
/*摆放一个皇后，如果能够摆放返回1，否  */
/*则返回0。                            */
/**************************************************/

int notEqual(int row,int j,int (*chess)[8])
{ 
   int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
   for(i=0;i<8;i++)
      if(*(*(chess+i)+j)!=0)
      {
        flag1=1;
        break;
      } /*判断列方向*/
	 
    for(i=row,k=j;i>=0 && k>=0;i--,k--)
         if(*(*(chess+i)+k)!=0)
         {
	flag2=1;
	break;
         }/*判断左上方*/

   for(i=row,k=j;i<8 && k<8;i++,k++)
        if(*(*(chess+i)+k)!=0)
        {
	flag3=1;
	break;
       }/*判断右下方向*/

   for(i=row,k=j;i>=0 && k<8;i--,k++)
       if(*(*(chess+i)+k)!=0)
       {
	flag4=1;
	break;
       }/*判断右上方向*/
  for(i=row,k=j;i<8 && k>=0;i++,k--)
     if(*(*(chess+i)+k)!=0)
     {
	flag5=1;
	break;
    }/*判断左下方向*/

   if(flag1==1||flag2==1||flag3==1
	   ||flag4==1||flag5==1)return 0;  /*如果有一个方向不符合要求，则返回0，*/
				/*表明第row行第j列不能摆放皇后*/
   else return 1;    /*否则返回1*/
}


/***************************************************/
/*EightQueen函数实现八皇后问题的递归   */
/*求解。当形成符合要求的八皇后棋盘局面  */
/*时，打印出棋盘的布局，用一个0-1矩阵  */
/*表示棋盘，0代表空，1代表皇后。      */
/*参数：row表示起始行；n表示列数等于8 */
/*(*chess)[8]为指向棋盘每一行的指针      */
/**************************************************/

EightQueen(int row,int n,int (*chess)[8])
{
    int j;
    int k,t;
    int chess2[8][8];
    for(int i=0;i<8;i++)
         for(j=0;j<8;j++)
             chess2[i][j]=*(*(chess+i)+j);		/*复制棋盘，用作递归使用*/
    if(row==8)							/*递归结束条件，形成符合要求的八皇后棋盘局面*/
       {
          for(k=0;k<8;k++){
            for(t=0;t<8;t++)
                printf("%d ",*(*(chess2+k)+t));      /*打印棋盘*/
            printf("\n");
          }
		  printf("\n\n");
		  getchar();
		  count++;                	 /*记录解的个数*/
       }
   else{                            	/*不符合递归结束条件，继续进行递归运算*/

    for(j=0;j<n;j++) {                    
        if(notEqual(row,j,chess))       /*判断棋盘的第row行第j列能否摆放一个皇后*/
        {
            for(i=0;i<8;i++)
	*(*(chess2+row)+i)=0;
            *(*(chess2+row)+j)=1;     		/*向棋盘的第row行第j列摆放皇后*/
          EightQueen (row+1,n,chess2);   	/*递归地调用EightQueen函数*/  
       }/*endif*/	
      }/*endfor*/
    }/*end else*/        
}

/*主函数*/
main()
{
   int chess[8][8],i,j;
   for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            chess[i][j]=0;                       /*初始化棋盘，全部置0*/

   EightQueen(0,8,chess);    /*调用 EightQueen函数，参数：n=0，row=8，*/
/*chess为指向棋盘每一行的指针  */             
   printf("The number of the answer for eightqueen is\n");     /*输出八皇后问题的解的个数*/
   printf("%d\n\n",count);
}
