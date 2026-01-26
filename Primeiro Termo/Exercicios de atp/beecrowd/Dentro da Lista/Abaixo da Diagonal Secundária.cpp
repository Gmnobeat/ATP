#include<stdio.h>
#define tf 12
int main()
{
	int x,y;
	char o;
	float soma,mat[tf][tf];
	scanf("%c",&o);
	for(y=0;y<tf;y++)
		for(x=0;x<tf;x++)
			scanf("%f",&mat[x][y]);
	soma=0;
	for(y=1;y<tf;y++)
		for(x=tf-1;x+y!=tf-1;x--)
			soma+=mat[x][y];
	if(o=='S')
		printf("%.1f\n",soma);
	else
		printf("%.1f\n",soma/((tf*tf/2)-tf));
	
}
