#ifndef CLASSES_QUEUE_EDGES_H
#define CLASSES_QUEUE_EDGES_H

#include "graph_structure.h"
#include "C:\Users\mstrz\CLionProjects\AiSD\Classes\Heap_Sort\heapsort.h"

void heapify_e(struct edge *tab, int i, int heap_size);
struct edge min_v_delete (struct edge *tab, int *heap_size);
void zmniejsz_wartosc_e (struct edge * tab, int i, struct edge a);
void wstaw_e (struct edge *tab, struct edge a, int *heap_size);

#endif //CLASSES_QUEUE_EDGES_H
