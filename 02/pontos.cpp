#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <float.h>

using namespace std;

typedef struct
{
        int x;
        int y;
} point;

double dist(point a, point b)
{
        return sqrt (pow (a.x - b.x, 2) + pow (a.y - b.y, 2));
}

int main()
{
        int n, i, j;
        point p;
        double d, min = DBL_MAX;
        vector<point> ps;

        scanf("%d", &n);

        for (i = 0; i < n; i++){
                scanf("%d %d", &p.x, &p.y);
                ps.push_back(p);
        }

        for (i = 0; i < n - 1; i++)
                for(j = i + 1; j < n; j++)
                {
                        d = dist(ps[i], ps[j]);
                        if(d < min)
                                min = d;
                }

        printf("%.3lf\n", min);
}
