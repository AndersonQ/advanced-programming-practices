#include <stdio.h>
#include <map>
using namespace std;

int main()
{
        int n, i, vote, win;
        long max;
        map<int, long> votes;
        map<int, long>::iterator it;

        max = 0;

        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
                scanf("%d", &vote);
                votes[vote]++;
        }

        it = votes.begin();

        for(; it != votes.end(); it++)
        {
                if(it->second > max)
                {
                        max = it->second;
                        win = it->first;
                }
        }

        printf("%d", win);
}
