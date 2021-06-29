#include "shortest_path.h"

void bellman_ford(struct edge *edges, int s, int n, int m, int *p, double *d) {
    d[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (d[edges[j].v] > d[edges[j].u] + edges[j].wage) {
                d[edges[j].v] = d[edges[j].u] + edges[j].wage;
                p[edges[j].v] = edges[j].u;
            }
        }
    }
}

int extract_min(int *q, double *d, int n) {
   int mini = -1;
   double key = INFINITY;
   for (int i = 0; i < n; i++) {
       if (d[i] < key && q[i] == 0) {
           key = d[i];
           mini = i;
           q[i] = 1;
       }
   }
   return mini;
}

int is_empty(const int *q, int n) {
    for (int i = 0; i < n; i++) {
        if (q[i] == 0) return 0;
    }
    return 1;
}

void dijkstra(struct edge *edges, int s, int n, int m, int *p, double *d) {
    d[s] = 0;
    int q[n];
    for (int i = 0; i < n; i++) q[i] = 0;
    int v;
    while (is_empty(q, n) == 0) {
        v = extract_min(q, d, n);
        for (int j = 0; j < m; j++) {
            if (edges[j].u == v) {
                if (d[edges[j].v] > d[edges[j].u] + edges[j].wage) {
                    d[edges[j].v] = d[edges[j].u] + edges[j].wage;
                    p[edges[j].v] = v;
                }
            }
        }
    }
}
