#ifndef CLASSES_MST_PRIM_H
#define CLASSES_MST_PRIM_H

#include "C:\Users\mstrz\CLionProjects\AiSD\Classes\Heap_Sort\heapsort.h"
#include "graph_structure.h"
#include "queue_edges.h"

struct el_listy3 {
    struct el_listy3 *nast;
    struct edge e;
};

void mst_prim(struct edge *ed, int s, int n, struct el_listy3 *successor[], int *predecessor);


#endif //CLASSES_MST_PRIM_H
