#ifndef CLASSES_SHORTEST_PATH_H
#define CLASSES_SHORTEST_PATH_H

#include "graph_structure.h"
#include <math.h>

void bellman_ford(struct edge *edges, int s, int n, int m, int *p, double *d);
int extract_min(int *q, double *d, int n);
int is_empty(const int *q, int n);
void dijkstra(struct edge *edges, int s, int n, int m, int *p, double *d);

#endif //CLASSES_SHORTEST_PATH_H
