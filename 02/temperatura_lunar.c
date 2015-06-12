#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
        int n, m, i, t, ts, *temps, tot, avg;
        int max, min;

        t = 0;
        max = INT_MIN;
        min = INT_MAX;

        scanf("%d %d", &n, &m);

        temps = (int *) malloc(sizeof(int) * n);

        while (n != 0 && m !=0) {

                for (i = 0; i < n; i++) {
                        scanf("%d", &ts);
                        temps[i] = ts;
                }

                tot = 0;
                for(i = 0; i < m; i++)
                        tot += temps[i];
                        
                        avg = tot / m;
                        if(min > avg)
                                min = avg;
                        if(max < avg)
                                max = avg;


                        for(i = m; i < n; i++)
                        {
                                tot -= temps[i - m];
                                tot += temps[i];

                                avg = tot / m;
                                if(min > avg)
                                        min = avg;
                                if(max < avg)
                                        max = avg;
                        }


                printf("Teste %d\n%d %d\n\n", ++t, min, max);

                scanf("%d %d", &n, &m);
                max = INT_MIN;
                min = INT_MAX;

                free(temps);
                temps = (int *) malloc(sizeof(int) * n);
        }

}
