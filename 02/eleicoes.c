#include <stdio.h>

#include <stdlib.h>

int main()
{
        int i, n;
        long votes[100001];
        int win, candidate, max = 0;

        scanf("%d", &n);

        if(n < 1)
                exit(0);

        for (i = 0; i < 100001; i++)
                votes[i] = 0;

        while (scanf("%d", &candidate) != EOF)
        {
                if (candidate < 1)
                        exit(0);

                if (max < ++votes[candidate])
                {
                        win = candidate;
                        max = votes[candidate];
                }
        }

        printf("%d", win);


}
