#include "stdio.h"
#include "math.h"

biTOde(int n,int *sum,int *m)
{
    char c;
    scanf("%c",&c);
    if(c!='#'){
        *m = *m +1;
        biTOde(n+1,&(*sum),&(*m));
    }
    if(c == '1') *sum = *sum + pow(2,(*m)-n-1);
}

main()
{
    int sum = 0,m=0;
    printf("Please input a binary number ending for '#'\n");
    biTOde(0,&sum,&m) ;
    printf("The Decimal Decimal digit is\n");
    printf("%d ",sum);
    getche();
}

