#include "stdio.h"

int func(int i)
{
	int j;
	for(j=10;j<1000;j=j*10)
	{
		if(i/j == 0)
			break;
	}
	if((i*i)%j == i)
		return 1;
	else
		return 0;
}
void gettonggou()
{
	int i;
	for(i=1;i<=1000;i++)
	{
		if(func(i))
			printf("%d ",i);
	}
}

main()
{
	printf("The Tonggoushu bellow 1000 are\n");
	gettonggou();
	printf("\n");
}
