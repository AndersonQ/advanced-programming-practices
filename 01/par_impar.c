#include <stdio.h>

int main()
{
	int n, i, a, b;
    int j = 1;
	char p1[11], p2[11];
	scanf("%d", &n);
	while(n != 0)
	{
		scanf("%s", p1);
		scanf("%s", p2);
        printf("Teste %d\n", j++);
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			((a + b) % 2 == 0)? puts(p1) : puts(p2);
		}
        puts("");
		scanf("%d", &n);
	}
}
