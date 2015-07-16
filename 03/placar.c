#include <stdio.h>
#include <string.h>

int main()
{
        char current_name[21], failed_name[21];
        int current_score, failed_score;
        int n, i;
        int t = 0;

        while (scanf("%d", &n) != EOF) {
                scanf("%s %d", failed_name, &failed_score);
                for (i = 1; i < n; i++) {
                        scanf("%s %d", current_name, & current_score);
                        if (failed_score > current_score ||
                            ((failed_score == current_score) && 
                             (strcmp(failed_name, current_name) < 0))) {
                                strcpy(failed_name, current_name);
                                failed_score = current_score;
                        }
                }

                printf("Instancia %d\n", ++t);
                printf("%s\n\n", failed_name);
        }

}
