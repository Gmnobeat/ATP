#include<stdio.h>
int main ()
{
	int i,j;
	float s=1;
	for (i=3,j=2;j<=39;i+=2,j*=2)
		s+=i/j;
	s=s*2;
	printf("%.2f\n",s);
	return 0;
}
