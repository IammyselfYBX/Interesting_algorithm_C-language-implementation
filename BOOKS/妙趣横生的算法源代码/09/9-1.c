#include "stdio.h"

int getWeight(int i,int j,int k,int s,int weight)
{
    int x1,x2,x3,x4;
    for(x1=-1;x1<=1;x1++)
        for(x2=-1;x2<=1;x2++)
            for(x3=-1;x3<=1;x3++)
                for(x4=-1;x4<=1;x4++)
                if(x1*i+x2*j+x3*k+x4*s == weight)  //存在一组解
                    return 1;
    return 0;
}

int justify(int i,int j,int k,int s)
{
    int weight;
    for(weight=1;weight<=40;weight++)
    {
        if(!getWeight(i,j,k,s,weight))
            return 0;
    }
    return 1;
}
pieces(){
    int i,j,k,s;

    for(i=1;i<=40;i++)
        for(j=i+1;j<=40-i;j++)
            for(k=j+1;k<=40-j-i;k++)
                for(s=k+1;s<=40-k-j-i;s++)
                    if(i+j+k+s==40)
                    {
                        if(justify(i,j,k,s)){
                           printf("The weight is broken up 4 pieces:\n");
                           printf("%d,%d,%d,%d",i,j,k,s);
                        }
                    }
}
main()
{
    pieces();
    getche();
}

