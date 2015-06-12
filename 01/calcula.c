#include<stdio.h>

int main()
{
    int n, i, a, res;
    int t = 1;
    char op;

    scanf("%i", &n);
    while(n > 0)
    {
        n--;
        scanf("%i", &res);
        for(i = 0; i < n; i++)
        {
            scanf("%c%i", &op, &a);
            res = (op == '+')? res + a : res - a;
        }
        printf("Teste %i\n%i\n\n", t++, res);
        scanf("%i", &n);
    }
}
