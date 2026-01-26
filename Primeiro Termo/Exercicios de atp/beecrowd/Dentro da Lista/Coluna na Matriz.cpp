#include<stdio.h>
#define tf 12
int main()
{
	int c,i,j;
	float mat[tf][tf],soma=0;
	char t;
	scanf("%d",&c);
	getchar();
	scanf("%c",&t);
	for(i=0;i<tf;i++)
		for(j=0;j<tf;j++)	
			scanf("%f",&mat[i][j]);
	for(i=0;i<tf;i++)
		soma+=mat[i][c];
	if(t=='S')
		printf("%.1f\n",soma);
	else
	{
		soma/=tf;
		printf("%.1f\n",soma);
	}
	return 0;
}
