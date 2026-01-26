#include<stdio.h>
#define tf 61
int main() 
{
    int t, n, i;
	double vet[tf];
    vet[0] = 0;
    vet[1] = 1;
    for (i = 2; i < tf; i++) 
        vet[i] = vet[i - 1] + vet[i - 2];
    scanf("%d", &t);
    i=0;
    while (i<t) 
	{
        scanf("%d", &n);
        printf("Fib(%d) = %.0lf\n", n, vet[n]);
        i++;
    }
    return 0;
}
