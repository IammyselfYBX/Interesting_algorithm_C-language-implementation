                 int IsNarcissus(int a);
void Narcissus();
void main()
{
    printf("The Narcissus numbers below are\n");
    Narcissus();
    getche();
}

void Narcissus()
{   /*寻找100-999之间的水仙花数*/
    int i;
    for(i=100;i<=999;i++)
        if(IsNarcissus(i))
            printf("%d ",i);
}

int IsNarcissus(int a)
{     /*判断是否是水仙花数，是则返回1，不是返回0*/
    int sum=0,tmp;
    tmp=a;
    while(tmp>0)
    {
        sum=sum+(tmp%10)* (tmp%10)*(tmp%10);
        tmp=tmp/10;

    }
    if(sum==a)
        return 1;         /*a 是水仙花数*/
    else
        return 0;         /* a 不是水仙花数*/
}

