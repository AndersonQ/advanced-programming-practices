#include <stdio.h>
#include <string.h>

#define MAX 31

typedef struct {
        char name[16];
        int in_d, out_d;
        int in_edges[MAX];
        int out_edges[MAX];
} Node;

int n;
Node graph[MAX];
int sorted[MAX];
int sorted_size = 0;

int find_node(char *name)
{
        int i;

        for (i = 0; i < n; i++) {
                if(!strcmp(name, graph[i].name))
                        return i;
        }

        fprintf(stderr, "Node '%s' no exist\n", name);
        return -1;
}

int topological_sort()
{
        int i;
        int s_size = 0;
        int s[MAX];
        int node;
        int m;

        sorted_size = 0;

        // build Set of all nodes with no incoming edges
        for (i = 0; i < n; i++) {
                if (graph[i].in_d == 0)
                        s[s_size++] = i;
        }

        while (s_size > 0) {
                node = s[--s_size];
                sorted[sorted_size++] = node;

                for (i = 0; i < graph[node].out_d; i++)
                {
                        m = graph[node].out_edges[i];
                        if(--(graph[m].in_d) == 0)
                                s[s_size++] = m;
                }
        }

        return (sorted_size != n) ? 0 : 1;
}

int main()
{
        int i, j;
        int node, dest, edges;
        int t = 0;
        char name[16];

        while (scanf("%d", &n)==1 && n) {
                /* build graph */
                for (i = 0; i < n; i++) {
                        scanf(" %s", graph[i].name);
                        graph[i].out_d = 0;
                        graph[i].in_d = 0;
                }

                /* add the edges */
                for (i = 0; i < n; i++) {
                        scanf(" %s %d", name, &edges);
                        node = find_node(name);

                        for (j = 0; j < edges; j++)
                        {
                                scanf("%s", name);
                                dest = find_node(name);

                                graph[node].out_edges[graph[node].out_d++] = dest;
                                graph[dest].in_edges[graph[dest].in_d++] = node;
                        }
                }

                printf("Teste %d\n", ++t);
                if (topological_sort()) {
                        printf("%s", graph[sorted[--n]].name);
                        for (i = --n; i > -1; i--)
                                printf(" %s", graph[sorted[i]].name);
                        puts("\n");
                } else {
                        puts("impossivel\n");
                }
        }
}
