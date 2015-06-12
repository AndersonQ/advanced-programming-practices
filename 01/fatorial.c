#include <stdio.h>

int main()
{
    int n, i, f;
    scanf("%i", &n);
    f = n;
    if(n == 0)
        f = n = 1;
    else
        for(i = n-1; i >= 2; i--)
            f = f * i;
            
    printf("%i\n", f);
}

