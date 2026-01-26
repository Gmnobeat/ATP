#include<stdio.h>
int main ()
{
	float sal,sal_final;
	scanf("%f",&sal);
	if (sal<=2000)
		printf("Isento\n");
	else	
			if (sal>2000 && sal<=3000)
			{
				sal_final=(sal-2000)*0.08;
				printf("R$ %.2f\n",sal_final);
			}	
			else
				if(sal>3000 && sal<4500)
				{
					sal_final=(sal-3000)*0.18;
					sal_final+=1000*0.08;
					printf("R$ %.2f\n",sal_final);
				}	
				else
					if(sal>=4500)
					{
						sal_final=(sal-4500)*0.28;
						sal_final+=1000*0.08+1500*0.18;
						printf("R$ %.2f\n",sal_final);
					}
		return 0;
}
