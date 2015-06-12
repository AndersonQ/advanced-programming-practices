#include <stdio.h>

int main()
{
        int n50, n10, n5, v, i = 0;

        scanf("%d", &v);

        while (v > 0){
                n50 = v / 50;
                v = v % 50;
                n10 = v / 10;
                v = v % 10;
                n5 = v / 5;
                v = v % 5;
                
                printf("Teste %d\n%d %d %d %d\n\n", ++i, n50, n10, n5, v);
                scanf("%d", &v);
        }
}
