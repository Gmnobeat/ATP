#include<stdio.h>
int main ()
{
	int n,soma,i,res;
	scanf("%d",&n);
	while(n>0)
	{
		res=n%2;
		if(res==1)
			n++;
		soma=0;
		for(i=0;i<5;i++)
			soma+=n+(2*i);
		printf("%d\n",soma);
		scanf("%d",&n);	
	}
	return 0;
}
