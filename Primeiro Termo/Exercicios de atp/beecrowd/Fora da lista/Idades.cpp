#include<stdio.h>
int main ()
{
	int id,i=0,soma=0;
	float media;
	scanf("%d",&id);
	while (id>0)
	{
		soma+=id;
		i++;
		scanf("%d",&id);
	}
	media=(float)soma/i;
	printf("%.2f\n",media);
	return 0;
}
