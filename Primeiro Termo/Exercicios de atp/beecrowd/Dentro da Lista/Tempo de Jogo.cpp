#include<stdio.h>
int main ()
{
	int hr,hr2;
	scanf("%d%d",&hr,&hr2);
	if(hr>hr2)
	{
		hr=24-hr;	
		hr=hr+hr2;
	}
	else
		if(hr==hr2)
			hr=24;
		else
			hr=hr2-hr;
	printf("O JOGO DUROU %d HORA(S)\n",hr);
}
