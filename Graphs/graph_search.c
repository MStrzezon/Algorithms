#include "graph_search.h"

typedef struct list_element list_element;

void bfs(struct edge *edges, int s, int n, int m, int *predecessor, int *d) {
    int visited[n];
    int u;
    int le = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        predecessor[i] = -1;
        d[i] = 0;
    }
    visited[s] = 1;
    enqueue(s);
    le++;
    while (le > 0) {
        u = (int)dequeue();
        le--;
        for (int i = 0; i < m; i++) {
            if (edges[i].u == u) {
                if (visited[edges[i].v] == 0) {
                    d[edges[i].v] = d[edges[i].u] + 1;
                    visited[edges[i].v] = 1;
                    predecessor[edges[i].v] = u;
                    enqueue(edges[i].v);
                    le++;
                }
            }
        }
    }
}

void bfs_better(struct edge *edges, int s, int n, int m, int *predecessor, int *d) {
    int visited[n];
    int u;
    int le = 0;
    struct list_element *ptr, *successors[n];
    for (int i = 0; i < n; i++) {
        predecessor[i] = -1;
        visited[i] = 0;
        successors[i] = 0;
        d[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        ptr = malloc(sizeof (list_element));
        ptr->vertex_to = edges[j].v;
        ptr->next = successors[edges[j].u];
        successors[edges[j].u] = ptr;
    }
    visited[s] = 1;
    enqueue(s);
    le++;
    while(le > 0) {
        u = (int)dequeue();
        le--;
        for (ptr = successors[u]; ptr != 0; ptr = ptr->next) {
            if (visited[ptr->vertex_to] == 0) {
                d[ptr->vertex_to] = d[u] + 1;
                visited[ptr->vertex_to] = 1;
                predecessor[ptr->vertex_to] = u;
                enqueue(ptr->vertex_to);
                le++;
            }
        }
    }
    struct list_element *delete;
    for (int i = 0; i < n; i++) {
        for (ptr = successors[i]; ptr;) {
            delete = ptr;
            ptr = ptr->next;
            free(delete);
        }
    }
}

void dfs(struct edge *edges, int s, int n, int m, int *predecessor, int *visited) {
    visited[s] = 1;
    for (int i = 0; i < m; i++) {
        if (edges[i].u == s) {
            if (visited[edges[i].v] == 0) {
                predecessor[edges[i].v] = s;
                dfs(edges, edges[i].v, n, m, predecessor, visited);
            }
        }
    }
}