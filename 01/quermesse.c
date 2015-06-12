#include <stdio.h>

int main()
{
        int n, i, t = 1;
        int ticket, winner;

        scanf("%d", &n);
        
        while(n > 0)
        {
                for(i = 1; i <= n; i++)
                {
                        scanf("%d", &ticket);
                        if(ticket == i)
                                winner = i;
                }

                printf("Teste %d\n%d\n\n", t++, winner);

                scanf("%d", &n);
        }
}
