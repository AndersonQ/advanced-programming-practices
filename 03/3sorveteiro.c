#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
        int b;
        int e;
} range;


void sort(range *r, int n)
{
        int i, j;
        range tmp;

        for (i = 1; i < n; i++)
                for (j = i; j < n-1; j++)
                        if (r[j].b > r[j+1].b) {
                                tmp = r[j];
                                r[j] = r[j+1];
                                r[j+1] = tmp;
                        }
}


int main()
{
        int i, b_length, ice_cream_men, b, e;
        range covered[10001];
        int beginning, end;
        int t = 0;

        scanf("%d %d", &b_length, &ice_cream_men);

        while (b_length != 0 && ice_cream_men != 0) {
                for (i = 0; i < ice_cream_men; i++) {
                        scanf("%d %d", &b, &e);
                        covered[i].b = b;
                        covered[i].e = e;
                }
                
                beginning = covered[0].b;
                end = covered[0].e;

                printf("Teste %d\n", ++t);

                for (i = 1; i < ice_cream_men; i++) {
                        while (i < ice_cream_men &&
                               covered[i].b <= end ) {
                                if (covered[i].e > end) 
                                        end = covered[i].e;
                                i++;
                        }
                        printf("%d %d\n", beginning, end);
                        beginning = covered[i].b;
                        end = covered[i].e;
                }

                if(i == ice_cream_men) {
                        printf("%d %d\n", beginning, end);
                }
                puts("");

                scanf("%d %d", &b_length, &ice_cream_men);
        }

}
