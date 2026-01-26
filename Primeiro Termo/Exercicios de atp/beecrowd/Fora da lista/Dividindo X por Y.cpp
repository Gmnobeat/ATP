#include<stdio.h>
int main ()
{
	int x,y,i,f;
	float resp;
	scanf("%d",&i);
	for(f=1;f<=i;f++)
	{
		scanf("%d%d",&x,&y);
		if(y==0)
			printf("divisao impossivel\n");
		else
		{
			resp=(float)x/y;
			printf("%.1f\n",resp);
		}
	}	
	return 0;		
}
