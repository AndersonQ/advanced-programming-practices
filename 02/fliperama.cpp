#include<stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int x , int y)
{
        return (x > y);
}

int main()
{
        int n, m, i, c, s;
        vector<int> ms;
        
        c = 0;

        scanf("%d %d", &n, &m);

        if (!(m <= n))
                exit(1);

        for (i = 0; i < n; i++){
                scanf("%d", &s);
                ms.push_back(s);
        }

        sort (ms.begin(), ms.end(), comp);

        for (i = 0; i < m; i++)
                printf("%d\n", ms[i]);

        exit(0);
}
