#include <stdio.h>
#include <stdlib.h>

void print_matrix(int n, int p, int** m)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++)
			printf("%5d ", m[i][j]);
		puts("");
	}
}

void print_vector(int n, int* v)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%d ", v[i]);
	puts("");
}

int** build_matrix(int n, int p)
{
        int i;
        int** m;
 
        m = (int **) malloc(sizeof(int *) * n); 
        if(m == NULL)
        {
                printf("Could not allocate a matrix with dimension %dx%d", n, p); 
                exit(1);
        }
     
        for(i = 0; i < n; i++)
        {
                m[i] = (int *) malloc(sizeof(int) * p); 
                if(m[i] == NULL)
                {
                        printf("Could not allocate a matrix with dimension %dx%d", n, p); 
                        exit(1);
                }
        }
 
        return m;
}

int max(int a, int b, int *p)
{
        if (a > b) {
                *p = 0;
                return a;
        } else {
                *p = 1;
                return b;
        }
}

void print_picked(int  N, int W, int * ws, int **z, int **p)
{
        int i;
        int n, w, *x;

        x = (int *) malloc(sizeof(int) * N);

        n = N - 1; 
        w = W;

        for (i = N; i > 0; i--)
        {
                x[i - 1] = p[w][n];
                if(p[w][n] == 1)
                        w = w - ws[n];
                n--;
        }

        printf("[");
        for (i = 0; i < N - 1; i++)
                printf("%d, ", x[i]);
        printf("%d]\n", x[N - 1]);
}

int main()
{
        int i, j, x, y;
        int n, b; /* n-> number of itens; b-> max weight*/
        int *vs; /* iten values*/ 
        int *ws; /* iten weights*/
        int **ps; /* the picked itens*/
        int **zs; /* the total value in the knapsack*/

        scanf("%d", &n);
        
        vs = (int *) malloc(sizeof(int) * n);
        ws = (int *) malloc(sizeof(int) * n);

        // get iten values
        for (i = 0; i < n; i++)
                scanf("%d", &vs[i]);
        // get iten weights
        for (i = 0; i < n; i++)
                scanf("%d", &ws[i]);

        scanf("%d", &b);

        //allocate matrices
        ps = build_matrix(b + 1, n);
        zs = build_matrix(b + 1, n);

        for (i = 0; i < n; i++)
                zs[0][i] = 0;

        for (i = 1; i <= b; i++)
                for (j = 0; j < n; j++) {
                        x = (j - 1 < 0) ? 0 : zs[i][j-1];
                        y = (i - ws[j] < 0) ? 0 : vs[j] + zs[i - ws[j]][j - 1];
                        zs[i][j] = max(x, y, &ps[i][j]);
                }

        print_matrix(b+1, n, zs);
        puts("");
        print_matrix(b+1, n, ps);
        printf("\nPicked: ");
        print_picked(n, b, ws, zs, ps);
        puts("");

}

