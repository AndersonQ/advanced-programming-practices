#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, total, b;
        int i, j, x, y, res;
        int t = 0;

        int vs[101];
        char m[101][10001];

        scanf("%d %d %d", &x, &y, &n);

        while ((x != 0) && (y != 0) && ( n != 0)) {
                total = 0;

                for (i = 1; i <= n; i++) {
                        scanf("%d", &vs[i]);
                        total += vs[i];
                }

                b = total + abs(x - y);

                if ((b < 0) ||((b % 2) != 0)) {
                        res = 0;
                }
                else if (b == 0) {
                        res = 1;
                }
                else {
                        b = b / 2;

                        for (i = 1; i <= b; i++)
                                m[1][i] = 0;

                        m[1][vs[1]] = 1;

                        for (i = 2; i <= n; i++)
                                for (j = 1; j <= b; j++) {
                                        if (j == vs[i])
                                                m[i][j] = 1;
                                        else if (j < vs[i])
                                                m[i][j] = m[i-1][j];
                                        else if (m[i-1][j] || m[i-1][j - vs[i]])
                                                m[i][j] = 1;
                                        else
                                                m[i][j] = 0;
                                }
                        res = m[n][b];
                }
                printf ("Teste %d\n%c\n\n", ++t, (res == 1) ? 'S' : 'N');
                scanf("%d %d %d", &x, &y, &n);
        
        }

}
