#include "stdio.h"
typedef struct student{
    int id;                /*学生编号*/
    char name[10];        /*学生姓名*/
    float score;            /*成绩*/ 
}Student;

int search(Student stu[],int n,int key){
    int i;
    for(i=0; i<n; i++)
        if( stu[i].id == key )            /*查找成功*/
            return i;               
    return -1;                         /*查找失败*/
 
}
main()
{
    Student stu[4] = {{1004,"TOM",100} ,    
                      {1002,"LILY",95},
                      {1001,"ANN",93},
                      {1003,"LUCY",98}
                      };                        /*初始化结构体数组*/
    int addr;                                /*要查找的记录的地址*/
    addr = search(stu,4,1001);
    printf("Student ID:   %d\n",stu[addr].id);         /*输出查找到的记录的信息*/
    printf("Student name: %s\n",stu[addr].name);
    printf("Student score: %f\n",stu[addr].score);
    getche();
}

