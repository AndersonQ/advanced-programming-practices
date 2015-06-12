#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a, v, i, x, y;
        int max, t = 0;
        int *fls;

        scanf("%d %d", &a, &v);

        while (a > 0 && v > 0)
        {
                fls = (int *) malloc(sizeof(int) * a);
 
                for (i = 0; i < v; i++)
                {
                        scanf("%d %d", &x, &y);
                        fls[x - 1]++;
                        fls[y - 1]++;
                }

                max = 0;
                for (i = 0; i < a; i++)
                        if(fls[i] > max)
                                max = fls[i];

                printf("Teste %d\n", ++t);
                
                for(i = 0; i < a; i++)
                        if(fls[i] == max)
                                printf("%d ", i+1);
                puts("\n");
                
                scanf("%d %d", &a, &v);
        }
}
