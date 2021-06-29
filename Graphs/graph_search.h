#ifndef CLASSES_GRAPH_SEARCH_H
#define CLASSES_GRAPH_SEARCH_H

#include "stdlib.h"
#include "C:\Users\mstrz\CLionProjects\AiSD\Classes\Queue\queue.h"
#include "graph_structure.h"

struct list_element {
    int vertex_to;
    struct list_element *next;
};

void bfs(struct edge *edges, int s, int n, int m, int *predecessor, int *d);
void bfs_better(struct edge *edges, int s, int n, int m, int *predecessor, int *d);
void dfs(struct edge *edges, int s, int n, int m, int *predecessor, int *visited);

#endif //CLASSES_GRAPH_SEARCH_H
