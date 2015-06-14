#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
        int b;
        int e;
} range;

int main()
{
        int i, j, b_length, ice_cream_men, b, e, size;
        range *covered;
        int stop = 0;
        int t = 0;

        scanf("%d %d", &b_length, &ice_cream_men);
        covered = (range *) malloc(sizeof(range) * 0);
        size = 0;

        while (b_length != 0 && ice_cream_men != 0) {
                for (i = 0; i < ice_cream_men; i++) {
                        
                        scanf("%d %d", &b, &e);
                        //stretch a renge
                        for (j = 0; j < size; j++) {
                                if (covered[j].b > b) {
                                        covered[i].b = b;
                                        stop = 1;
                                }
                                if (covered[j].b >= b && covered[j].e < e) {
                                        covered[j].e = e;
                                        stop = 1;
                                }
                                if(stop)
                                        break;
                        }

                        //outside the range
                        if (size == 0 || covered[size-1].e < b) {
                                covered = (range *) realloc(covered, (++size) * sizeof(range *));
                                covered[size-1].b = b;
                                covered[size-1].e = e;
                        }
                }

                printf("Teste %d\n", ++t);
                for (i = 0; i < size; i++)
                        printf("%d %d\n", covered[i].b, covered[i].e);
                puts("");

                scanf("%d %d", &b_length, &ice_cream_men);
                covered = (range *) malloc(sizeof(range) * 0);
                size = 0;
        }

}
