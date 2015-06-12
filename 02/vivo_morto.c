#include <stdio.h>
#include <stdlib.h>

int main()
{
        int i, j, r, t, n, m, playing, command;
        int *order, *players;
        int tmp;

        t = 0;
        scanf("%d %d", &n, &m);

        order = (int *) malloc(sizeof(int) * n);
        players = (int *) malloc(sizeof(int) * n);

        while (n != 0 && m != 0){
                for (i = 0; i < n ; i++) {
                        scanf("%d", &tmp);
                        order[i] = tmp;
                        players[i] = 1;
                }


                for (r = 0; r < m; r++) {
		            scanf("%d", &playing);
		            scanf("%d", &command);

                            /*printf("r: %d, playing: %d, c: %d\n", r, playing, command);*/

                            j = 0;
		            for (i = 0; i < playing; i++) {
		                    scanf("%d", &tmp);

		                    while (players[j] == 0 && j < m) {j++;}

                                    /*printf("i: %d, j:%d -> p%d\n", i, j, order[j]);*/
		                   
		                    if (command != tmp)
                                    {
                                     //       printf("r: %d, p%d[%d] loses\n", r, order[j], j);
		                            players[j] = 0;
                                    }
                                    j++;

		            }

                }

                for(i = 0; i < m; i++)
                        if (players[i] == 1)
                                break;

                printf("Teste %d\n%d\n", ++t, order[i]);

                scanf("%d %d", &n, &m);
                free(order);
                free(players);
                order = (int *) malloc(sizeof(int) * n);
                players = (int *) malloc(sizeof(int) * n);
        }
        free(order);
        free(players);
}

