#include<stdio.h>
#include<math.h>
int main ()
{
	int n,i=1,x,y;
	scanf("%d",&n);
	while(n>=i)
	{
		x=pow(i,2);
		y=i*x;
		printf("%d %d %d\n",i,x,y);
		printf("%d %d %d\n",i,x+1,y+1);
		i=i+1;
	}
	return 0;
}
