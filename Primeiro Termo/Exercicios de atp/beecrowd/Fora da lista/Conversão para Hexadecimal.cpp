#include <stdio.h>
#define tf 20
int main() 
{
    int numero, resto, j = 0, i;
    char alf[] = {'A','B','C','D','E','F'}, resp[tf];
    scanf("%d", &numero);
    if (numero == 0) 
	{
        printf("0\n");
        return 0;
    }
    while(numero > 0) 
	{
        resto = numero % 16;
        if (resto > 9)
            resp[j] = alf[resto - 10];
        else
            resp[j] = resto + '0';
        numero = numero / 16;
        j++;
    }
    for(i = j - 1; i >= 0; i--)
        printf("%c", resp[i]);
    printf("\n");
    return 0;
}
