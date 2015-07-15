/*
 * Se N ≤ 100, então f91 (N) = f91 (f91 (N + 11));
 * Se N ≥ 101, então f91 (N) = N - 10.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define F91(n, x) printf("f91(%d) = %d\n", n, x)

int main()
{
        int n;

        scanf("%d", &n);
        
        while(n > 0) {
                if (n >100)
                        F91(n, n - 10);
                else
                        F91(n, 91);

                scanf("%d", &n);
        }
}
