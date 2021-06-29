#ifndef CLASSES_HEAPSORT_H
#define CLASSES_HEAPSORT_H

#include <stdio.h>

int parent(int i);
int left(int i);
int right(int i);
void heapify(double *tab, int i, int heap_size);
void build_heap(double *tab, int heap_size);
void heapsort(double *tab, int heap_size);

#endif //CLASSES_HEAPSORT_H
