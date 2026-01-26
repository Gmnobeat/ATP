#include<stdio.h>
int main ()
{
	int F=50;
	float C;
	printf("+--------------+---------------+\n");
	printf("|  farenheit   |  centigrados  |\n");
	printf("+--------------+---------------+\n");
	while(F<=65)
	{
		F++;
		C=(float)(F-32)*5/9;
		printf("|     %d       |     %.2f     |\n",F,C);
		printf("+--------------+---------------+\n");
	}
}
