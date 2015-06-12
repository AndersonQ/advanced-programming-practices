#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int n)
{
        int i;
        int **m;
        m = (int **) malloc(sizeof(int *) * n);

        for(i = 0; i < n ; i++)
                m[i] = (int *) malloc(sizeof(int) * n);
        return m;
}

void init_matrix(int n, int **m)
{
        int i, j;

        for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                        m[i][j] = 0;
}

int check_row(int *l)
{
        int i, tmp = 1;
        int *v;

        v = (int *) malloc(sizeof(int) * 9);
        for(i = 0; i < 9; i++)
                v[i] = 0;
        
        for(i = 0; i < 9; i++)
                v[l[i] - 1] = 1;

        for(i = 0; i < 9; i++)
                tmp *= v[i];

        return tmp;
}

int check_column(int c, int **m)
{
        int i;
        int *v;

        v = (int *) malloc(sizeof(int) * 9);
        for(i = 0; i < 9; i++)
                v[i] = m[i][c];

        return check_row(v);
}

int check_matrix(int r, int c, int **m)
{
        int i, j, k = 0;
        int *l;

        l = (int *) malloc(sizeof(int) * 9);
        for(i = 0; i < 9; i++)
                l[i] = 1;
       
        for(i = r; i < r+3; i++)
                for(j = c; j < c+3; j++)
                        l[k ++] = m[i][j];
        
        return check_row(l);
}

char *check_sudoku(int **m)
{
        int i, j;
        int ret = 1;

        for(i = 0; i < 9; i++)
                ret *= check_row(m[i]) * check_column(i, m);

        if(ret != 1)
                return "NAO";

        for(i = 0; i < 9; i += 3)
                for(j = 0; j < 9; j += 3)
                        ret *= check_matrix(i, j, m);

        return ret == 1? "SIM" : "NAO";
}

void read_matrix(int **m)
{
        int i, j;
        for(i = 0; i < 9; i++)
                for(j = 0; j < 9; j++)
                        scanf("%d", &m[i][j]);
}

int main()
{
        int i, n;
        int **m;

        scanf("%d", &n);
        
        for(i = 0; i < n; i++)
        {
                m = allocate_matrix(9);
                read_matrix(m);
                printf("Instancia %d\n%s\n\n", i+1, check_sudoku(m));
        }
}
