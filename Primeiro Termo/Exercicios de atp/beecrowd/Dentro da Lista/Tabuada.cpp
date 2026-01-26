#include<stdio.h>
int main()
{
	int n,i=1,resp;
	scanf("%d",&n);
	while(i<11)
	{
		resp=n*i;
		printf("%d x %d = %d\n",i,n,resp);
		i=i+1;
	}
}
