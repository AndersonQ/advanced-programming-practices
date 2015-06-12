#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, t, i, a, b, sa, sb;

        t = 0;

        scanf("%d", &n);

        while (n != 0) {
                a = b = 0;
                for (i = 0; i < n; i++) {
                        scanf("%d %d", &sa, &sb);
                        a += sa;
                        b += sb;
                }

                printf("Teste %d\n%s\n\n", 
                                ++t,
                                a >  b ? "Aldo" : "Beto");
                scanf("%d", &n);
        }
}
