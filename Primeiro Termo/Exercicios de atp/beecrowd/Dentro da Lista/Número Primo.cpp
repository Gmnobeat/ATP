#include <stdio.h>
#include <math.h>

int main() {
    int n, n1, i = 0;
    
    scanf("%d", &n); 
    
    while (n > i) {
        scanf("%d", &n1); 
        int primo = 1; 
        
        if (n1 < 2) { 
            primo = 0;
        } else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
            primo = 1; 
        } else if (n1 % 2 == 0) {
            primo = 0; 
        } else {      
            for (int d = 3; d <= sqrt(n1); d += 2) {
                if (n1 % d == 0) {
                    primo = 0; 
                    break;
                }
            }
        }

        if (primo)
            printf("%d eh primo\n", n1);
        else
            printf("%d nao eh primo\n", n1);

        i++;
    }

    return 0;
}
